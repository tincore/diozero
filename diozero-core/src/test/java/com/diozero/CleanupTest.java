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


import java.io.IOException;
import java.nio.ByteBuffer;

import org.junit.Assert;
import org.junit.Test;

import com.diozero.api.*;
import com.diozero.internal.provider.test.TestDeviceFactory;
import com.diozero.internal.spi.DeviceStates;
import com.diozero.internal.spi.I2CDeviceInterface;
import com.diozero.internal.spi.SpiDeviceInterface;

@SuppressWarnings("static-method")
public class CleanupTest {
	@Test
	public void test() {
		TestDeviceFactory tdf = (TestDeviceFactory)DeviceFactoryHelper.getNativeDeviceFactory();
		DeviceStates ds = tdf.getDeviceStates();
		Assert.assertTrue(ds.size() == 0);
		try (I2CDeviceInterface device = tdf.provisionI2CDevice(0, 0, 0, 0)) {
			device.read(0, I2CConstants.ADDR_SIZE_7, ByteBuffer.allocateDirect(5));
			Assert.assertTrue(ds.size() == 1);
			device.close();
			Assert.assertTrue(ds.size() == 0);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		// Check the log for the above - make sure there is a warning about closing already closed device
		
		Assert.assertTrue(ds.size() == 0);
		try (SpiDeviceInterface device = tdf.provisionSpiDevice(0, 0, 0, SpiClockMode.MODE_0)) {
			ByteBuffer out = ByteBuffer.allocate(3);
			out.put((byte) 0x01);
			out.put((byte) ((1 | 0x08) << 4));
			out.put((byte) 0);
			out.flip();
			device.writeAndRead(out);
			Assert.assertTrue(ds.size() == 1);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Assert.assertTrue(ds.size() == 0);
		tdf.closeAll();
	}
}