/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_diozero_internal_provider_builtin_i2c_NativeI2C */

#ifndef _Included_com_diozero_internal_provider_builtin_i2c_NativeI2C
#define _Included_com_diozero_internal_provider_builtin_i2c_NativeI2C
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    getFuncs
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_getFuncs
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    selectSlave
 * Signature: (IIZ)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_selectSlave
  (JNIEnv *, jclass, jint, jint, jboolean);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    smbusOpen
 * Signature: (Ljava/lang/String;IZ)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_smbusOpen
  (JNIEnv *, jclass, jstring, jint, jboolean);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    smbusClose
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_smbusClose
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    writeQuick
 * Signature: (IB)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_writeQuick
  (JNIEnv *, jclass, jint, jbyte);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readByte
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readByte
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    writeByte
 * Signature: (IB)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_writeByte
  (JNIEnv *, jclass, jint, jbyte);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readByteData
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readByteData
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    writeByteData
 * Signature: (IIB)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_writeByteData
  (JNIEnv *, jclass, jint, jint, jbyte);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readWordData
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readWordData
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    writeWordData
 * Signature: (IIS)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_writeWordData
  (JNIEnv *, jclass, jint, jint, jshort);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readWordSwapped
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readWordSwapped
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    writeWordSwapped
 * Signature: (IIS)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_writeWordSwapped
  (JNIEnv *, jclass, jint, jint, jshort);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    processCall
 * Signature: (IIS)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_processCall
  (JNIEnv *, jclass, jint, jint, jshort);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readBlockData
 * Signature: (II[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readBlockData
  (JNIEnv *, jclass, jint, jint, jbyteArray);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    writeBlockData
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_writeBlockData
  (JNIEnv *, jclass, jint, jint, jint, jbyteArray);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    blockProcessCall
 * Signature: (III[B[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_blockProcessCall
  (JNIEnv *, jclass, jint, jint, jint, jbyteArray, jbyteArray);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readI2CBlockData
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readI2CBlockData
  (JNIEnv *, jclass, jint, jint, jint, jbyteArray);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    writeI2CBlockData
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_writeI2CBlockData
  (JNIEnv *, jclass, jint, jint, jint, jbyteArray);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readBytes
 * Signature: (II[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readBytes
  (JNIEnv *, jclass, jint, jint, jbyteArray);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    writeBytes
 * Signature: (II[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_writeBytes
  (JNIEnv *, jclass, jint, jint, jbyteArray);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readNoStop
 * Signature: (IIBI[BZ)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readNoStop
  (JNIEnv *, jclass, jint, jint, jbyte, jint, jbyteArray, jboolean);

/*
 * Class:     com_diozero_internal_provider_builtin_i2c_NativeI2C
 * Method:    readWrite
 * Signature: (II[Lcom/diozero/api/I2CDeviceInterface/I2CMessage;[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_builtin_i2c_NativeI2C_readWrite
  (JNIEnv *, jclass, jint, jint, jobjectArray, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif
