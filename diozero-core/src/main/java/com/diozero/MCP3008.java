package com.diozero;

/*
 * #%L
 * Device I/O Zero - Core
 * %%
 * Copyright (C) 2016 diozero
 * %%
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * #L%
 */

import java.io.Closeable;
import java.nio.ByteBuffer;

import org.pmw.tinylog.Logger;

import com.diozero.api.DeviceAlreadyOpenedException;
import com.diozero.api.SpiDevice;
import com.diozero.internal.provider.mcp3008.MCP3008AnalogueInputPin;
import com.diozero.internal.spi.AbstractDeviceFactory;
import com.diozero.internal.spi.AnalogueInputDeviceFactoryInterface;
import com.diozero.internal.spi.GpioAnalogueInputDeviceInterface;
import com.diozero.util.RuntimeIOException;

/**
 * Encapsulate MCP3008 SPI device functionality
 */
public class MCP3008 extends AbstractDeviceFactory implements AnalogueInputDeviceFactoryInterface, Closeable {
	private static final String DEVICE_NAME = "MCP3008";
	private static final int NUM_PINS = 8;
	// 10bit ADC
	private static final int RESOLUTION = 10;
	private static final float DEFAULT_VOLTAGE = 3.3f;
	
	private SpiDevice spiDevice;
	private String keyPrefix;
	private float voltage;
	private final int range;
	private int resolution = RESOLUTION;
	private int numPins = NUM_PINS;
	private String deviceName = DEVICE_NAME;

	public MCP3008(int chipSelect) throws RuntimeIOException {
		this(0, chipSelect, DEFAULT_VOLTAGE);
	}

	public MCP3008(int controller, int chipSelect) throws RuntimeIOException {
		this(controller, chipSelect, DEFAULT_VOLTAGE);
	}

	public MCP3008(int controller, int chipSelect, float voltage) throws RuntimeIOException {
		spiDevice = new SpiDevice(controller, chipSelect);
		this.voltage = voltage;
		keyPrefix = deviceName + "-" + controller + "-" + chipSelect + "-";
		range = (int)Math.pow(2, resolution);
	}
	
	@Override
	public void close() throws RuntimeIOException {
		Logger.debug("close()");
		// Close all open pins before closing the SPI device itself
		closeAll();
		spiDevice.close();
	}

	/**
	 * Read the raw 10bit value (0-1023)
	 * @throws RuntimeIOException 
	 */
	public int getRawValue(int adcPin) throws RuntimeIOException {
		if (adcPin < 0 || adcPin >= numPins) {
			throw new IllegalArgumentException(
					"Invalid channel number (" + adcPin + "), must be >= 0 and < " + numPins);
		}

		ByteBuffer out = ByteBuffer.allocate(3);
		out.put((byte) 0x01);
		out.put((byte) ((adcPin | 0x08) << 4));
		out.put((byte) 0);
		out.flip();
		ByteBuffer in = spiDevice.writeAndRead(out);
		// TODO Logic as to how many bits to mask out based on resolution
		int high = 0x03 & in.get(1);
		int low = 0xff & in.get(2);

		return (high << 8) | low;
	}

	public float getVoltage(int adcPin) throws RuntimeIOException {
		int r = getRawValue(adcPin);
		// r will be 0..1023
		return (r / (float)(range-1)) * voltage;
	}
	
	public float getVoltageRange() {
		return voltage;
	}

	@Override
	public String getName() {
		return deviceName + "-" + spiDevice.getController() + "-" + spiDevice.getChipSelect();
	}

	/**
	 * Device Factory SPI method, use {@link provisionAnalogueInputDevice} instead
	 */
	@Override
	public GpioAnalogueInputDeviceInterface provisionAnalogueInputPin(int pinNumber)
			throws RuntimeIOException {
		if (pinNumber < 0 || pinNumber >= numPins) {
			throw new IllegalArgumentException(
					"Invalid channel number (" + pinNumber + "), must be >= 0 and < " + numPins);
		}
		
		String key = keyPrefix + pinNumber;
		
		if (isDeviceOpened(key)) {
			throw new DeviceAlreadyOpenedException("Device " + key + " is already in use");
		}
		
		GpioAnalogueInputDeviceInterface device = new MCP3008AnalogueInputPin(this, key, pinNumber);
		deviceOpened(device);
		
		return device;
	}
}