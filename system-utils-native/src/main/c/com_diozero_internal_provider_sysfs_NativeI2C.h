/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_diozero_internal_provider_sysfs_NativeI2C */

#ifndef _Included_com_diozero_internal_provider_sysfs_NativeI2C
#define _Included_com_diozero_internal_provider_sysfs_NativeI2C
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    getFuncs
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_getFuncs(
		JNIEnv* env, jclass clz, jint fd);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    selectSlave
 * Signature: (IIZ)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_selectSlave(
		JNIEnv* env, jclass clz, jint fd, jint deviceAddress, jboolean force);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    smbusOpen
 * Signature: (Ljava/lang/String;IZ)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_smbusOpen(
		JNIEnv* env, jclass clz, jstring i2cAdapter, jint deviceAddress, jboolean force);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    smbusClose
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_smbusClose(
		JNIEnv* env, jclass clz, jint fd);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    writeQuick
 * Signature: (IB)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_writeQuick(
		JNIEnv* env, jclass clz, jint fd, jbyte value);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    readByte
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_readByte(
		JNIEnv* env, jclass clz, jint fd);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    writeByte
 * Signature: (IB)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_writeByte(
		JNIEnv* env, jclass clz, jint fd, jbyte value);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    readBytes
 * Signature: (II[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_readBytes(
		JNIEnv* env, jclass clz, jint fd, jint rxLength, jbyteArray rxData);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    writeBytes
 * Signature: (II[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_writeBytes(
		JNIEnv* env, jclass clz, jint fd, jint txLength, jbyteArray txData);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    readByteData
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_readByteData(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    writeByteData
 * Signature: (IIB)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_writeByteData(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress, jbyte value);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    readWordData
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_readWordData(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    writeWordData
 * Signature: (IIS)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_writeWordData(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress, jshort value);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    processCall
 * Signature: (IIS)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_processCall(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress, jshort value);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    readBlockData
 * Signature: (II[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_readBlockData(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress, jbyteArray rxData);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    writeBlockData
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_writeBlockData(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress, jint txLength, jbyteArray txData);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    blockProcessCall
 * Signature: (III[B[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_blockProcessCall(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress, jint txLength, jbyteArray txData, jbyteArray rxData);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    readI2CBlockData
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_readI2CBlockData(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress, jint rxLength, jbyteArray rxData);

/*
 * Class:     com_diozero_internal_provider_sysfs_NativeI2C
 * Method:    writeI2CBlockData
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_com_diozero_internal_provider_sysfs_NativeI2C_writeI2CBlockData(
		JNIEnv* env, jclass clz, jint fd, jint registerAddress, jint txLength, jbyteArray txData);

#ifdef __cplusplus
}
#endif
#endif
