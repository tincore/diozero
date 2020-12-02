package com.diozero.sampleapps;

/*-
 * #%L
 * Organisation: diozero
 * Project:      Device I/O Zero - Sample applications
 * Filename:     BME680Test.java  
 * 
 * This file is part of the diozero project. More information about this project
 * can be found at http://www.diozero.com/
 * %%
 * Copyright (C) 2016 - 2020 diozero
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

import com.diozero.devices.BME680;
import com.diozero.util.SleepUtil;

/**
 * BME680 temperature / pressure / humidity sensor sample application. To run:
 * <ul>
 * <li>Built-in:<br>
 * {@code java -cp tinylog-api-$TINYLOG_VERSION.jar:tinylog-impl-$TINYLOG_VERSION.jar:diozero-core-$DIOZERO_VERSION.jar:diozero-sampleapps-$DIOZERO_VERSION.jar com.diozero.sampleapps.BME680Test}</li>
 * <li>pigpgioj:<br>
 * {@code sudo java -cp tinylog-api-$TINYLOG_VERSION.jar:tinylog-impl-$TINYLOG_VERSION.jar:diozero-core-$DIOZERO_VERSION.jar:diozero-sampleapps-$DIOZERO_VERSION.jar:diozero-provider-pigpio-$DIOZERO_VERSION.jar:pigpioj-java-2.4.jar com.diozero.sampleapps.BME680Test}</li>
 * </ul>
 */
public class BME680Test {
	public static void main(String[] args) {
		int controller = 0;
		if (args.length > 0) {
			controller = Integer.parseInt(args[0]);
		}
		
		try (BME680 bme680 = new BME680(controller)) {
			bme680.setHumidityOversample(BME680.OversamplingMultiplier.X2);
			bme680.setPressureOversample(BME680.OversamplingMultiplier.X4);
			bme680.setTemperatureOversample(BME680.OversamplingMultiplier.X8);
			bme680.setFilter(BME680.FilterSize.SIZE_3);
			bme680.setGasMeasurementEnabled(true);
			
			bme680.setGasConfig(BME680.HeaterProfile.PROFILE_0, 320, 150);
			
			for (int i = 0; i < 20; i++) {
				BME680.Data data = bme680.getSensorData();
				System.out.format(
						"Temperature: %.2f C. Pressure: %.2f hPa. Relative Humidity: %.2f %%rH. Gas Resistance: %.2f Ohms (stable: %b). Air Quality: %.2f ??.%n",
						Float.valueOf(data.getTemperature()), Float.valueOf(data.getPressure()),
						Float.valueOf(data.getHumidity()), Float.valueOf(data.getGasResistance()),
						Boolean.valueOf(data.isHeaterTempStable()), Float.valueOf(data.getAirQualityScore()));

				SleepUtil.sleepSeconds(1);
			}
		}
	}
}
