package com.diozero.util;

/*
 * #%L
 * Device I/O Zero - Core
 * %%
 * Copyright (C) 2016 mattjlewis
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
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;

import org.pmw.tinylog.Logger;

public class LibraryLoader {
	public static void loadLibrary(Class<?> clz, String libName) throws UnsatisfiedLinkError {
		;
		try {
			// First try load the library from within the JAR file
			Path path = Files.createTempFile("lib" + libName, ".so");
			path.toFile().deleteOnExit();
			Files.copy(clz.getResourceAsStream("/lib/" + SystemInfo.getOperatingSystemId() + "/lib" + libName + ".so"), path,
					StandardCopyOption.REPLACE_EXISTING);
			Runtime.getRuntime().load(path.toString());
		} catch (NullPointerException | IOException e) {
			Logger.info(e, "Error loading library from classpath: " + e);

			// Try load from the Java system library path (-Djava.library.path)
			System.loadLibrary(libName);
		}
	}
}
