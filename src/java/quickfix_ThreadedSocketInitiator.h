/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class quickfix_ThreadedSocketInitiator */

#ifndef _Included_quickfix_ThreadedSocketInitiator
#define _Included_quickfix_ThreadedSocketInitiator
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     quickfix_ThreadedSocketInitiator
 * Method:    create
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_quickfix_ThreadedSocketInitiator_create
  (JNIEnv *, jobject);

/*
 * Class:     quickfix_ThreadedSocketInitiator
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_quickfix_ThreadedSocketInitiator_destroy
  (JNIEnv *, jobject);

/*
 * Class:     quickfix_ThreadedSocketInitiator
 * Method:    doStart
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_quickfix_ThreadedSocketInitiator_doStart
  (JNIEnv *, jobject);

/*
 * Class:     quickfix_ThreadedSocketInitiator
 * Method:    doBlock
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_quickfix_ThreadedSocketInitiator_doBlock
  (JNIEnv *, jobject);

/*
 * Class:     quickfix_ThreadedSocketInitiator
 * Method:    doPoll
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_quickfix_ThreadedSocketInitiator_doPoll
  (JNIEnv *, jobject);

/*
 * Class:     quickfix_ThreadedSocketInitiator
 * Method:    doStop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_quickfix_ThreadedSocketInitiator_doStop__
  (JNIEnv *, jobject);

/*
 * Class:     quickfix_ThreadedSocketInitiator
 * Method:    doStop
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_quickfix_ThreadedSocketInitiator_doStop__Z
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     quickfix_ThreadedSocketInitiator
 * Method:    doIsLoggedOn
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_quickfix_ThreadedSocketInitiator_doIsLoggedOn
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
