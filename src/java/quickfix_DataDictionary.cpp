/* ====================================================================
* The QuickFIX Software License, Version 1.0
*
* Copyright (c) 2004 ThoughtWorks, Inc.  All rights
* reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*
* 3. The end-user documentation included with the redistribution,
*    if any, must include the following acknowledgment:
*       "This product includes software developed by
*        ThoughtWorks, Inc. (http://www.thoughtworks.com/)."
*    Alternately, this acknowledgment may appear in the software itself,
*    if and wherever such third-party acknowledgments normally appear.
*
* 4. The names "QuickFIX" and "ThoughtWorks, Inc." must
*    not be used to endorse or promote products derived from this
*    software without prior written permission. For written
*    permission, please contact quickfix-users@lists.sourceforge.net.
*
* 5. Products derived from this software may not be called "QuickFIX",
*    nor may "QuickFIX" appear in their name, without prior written
*    permission of ThoughtWorks, Inc.
*
* THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED.  IN NO EVENT SHALL THOUGHTWORKS INC OR
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
* USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
* ====================================================================
*/

#ifdef _MSC_VER
#include "stdafx.h"
#else
#include "config.h"
#endif

#include "JVM.h"
#include "Conversions.h"
#include "quickfix_DataDictionary.h"
#include <quickfix/DataDictionary.h>
#include <quickfix/CallStack.h>
#include <string>

JNIEXPORT void JNICALL Java_quickfix_DataDictionary_create__
( JNIEnv *pEnv, jobject obj )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );

  FIX::DataDictionary* pDataDictionary = new FIX::DataDictionary();

  jobject.setInt( "cppPointer", ( int ) pDataDictionary );

  QF_STACK_CATCH
}

JNIEXPORT void JNICALL Java_quickfix_DataDictionary_create__Lquickfix_DataDictionary_2
( JNIEnv *pEnv, jobject obj, jobject dd )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  JVMObject jdd( dd );

  FIX::DataDictionary* pOldDataDictionary =
    ( FIX::DataDictionary* ) jdd.getInt( "cppPointer" );
  FIX::DataDictionary* pDataDictionary = new FIX::DataDictionary( *pOldDataDictionary );

  jobject.setInt( "cppPointer", ( int ) pDataDictionary );

  QF_STACK_CATCH
}

JNIEXPORT void JNICALL Java_quickfix_DataDictionary_create__Ljava_lang_String_2
( JNIEnv *pEnv, jobject obj, jstring url )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );

  const char* uurl = pEnv->GetStringUTFChars( url, 0 );
  std::string urlString( uurl );
  pEnv->ReleaseStringUTFChars( url, uurl );

  FIX::DataDictionary* pDataDictionary = new FIX::DataDictionary( urlString );

  jobject.setInt( "cppPointer", ( int ) pDataDictionary );

  QF_STACK_CATCH
}

JNIEXPORT void JNICALL Java_quickfix_DataDictionary_destroy
( JNIEnv *pEnv, jobject obj )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  delete pDataDictionary;

  QF_STACK_CATCH
}

JNIEXPORT jstring JNICALL Java_quickfix_DataDictionary_getVersion
( JNIEnv *pEnv, jobject obj )
{ QF_STACK_TRY
  
  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  jstring result = newString( pDataDictionary->getVersion() );
  return result;

  QF_STACK_CATCH
}

JNIEXPORT jstring JNICALL Java_quickfix_DataDictionary_getFieldName
( JNIEnv *pEnv, jobject obj, jint field ) 
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  std::string nameString;
  bool result = pDataDictionary->getFieldName(field, nameString);
  return result ? newString(nameString) : 0;

  QF_STACK_CATCH
}

JNIEXPORT jstring JNICALL Java_quickfix_DataDictionary_getValueName
( JNIEnv *pEnv, jobject obj, jint field, jstring value )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  const char* uvalue = pEnv->GetStringUTFChars( value, 0 );
  std::string valueString( uvalue );
  pEnv->ReleaseStringUTFChars( value, uvalue );
  std::string nameString;
  bool result = pDataDictionary->getValueName( field, valueString, nameString );
  return result ? newString(nameString) : 0;

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_isField
( JNIEnv *pEnv, jobject obj, jint field )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  return pDataDictionary->isField( field );

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_isMsgType
( JNIEnv *pEnv, jobject obj, jstring msgType )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  const char* umsgType = pEnv->GetStringUTFChars( msgType, 0 );
  std::string msgTypeString( umsgType );
  pEnv->ReleaseStringUTFChars( msgType, umsgType );
  return pDataDictionary->isMsgType( msgTypeString );

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_isMsgField
( JNIEnv *pEnv, jobject obj, jstring msgType, jint field )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  const char* umsgType = pEnv->GetStringUTFChars( msgType, 0 );
  std::string msgTypeString( umsgType );
  pEnv->ReleaseStringUTFChars( msgType, umsgType );
  return pDataDictionary->isMsgField( msgTypeString, field );

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_isHeaderField
( JNIEnv *pEnv, jobject obj, jint field )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  return pDataDictionary->isHeaderField( field );

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_isTrailerField
( JNIEnv *pEnv, jobject obj, jint field )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  return pDataDictionary->isTrailerField( field );

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_isRequiredField
( JNIEnv *pEnv, jobject obj, jstring msgType, jint field )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  const char* umsgType = pEnv->GetStringUTFChars( msgType, 0 );
  std::string msgTypeString( umsgType );
  pEnv->ReleaseStringUTFChars( msgType, umsgType );
  return pDataDictionary->isRequiredField( msgTypeString, field );

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_hasFieldValue
( JNIEnv *pEnv, jobject obj, jint field )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  return pDataDictionary->hasFieldValue( field );

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_isFieldValue
( JNIEnv *pEnv, jobject obj, jint field, jstring value )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  const char* uvalue = pEnv->GetStringUTFChars( value, 0 );
  std::string valueString( uvalue );
  pEnv->ReleaseStringUTFChars( value, uvalue );
  return pDataDictionary->isFieldValue( field, valueString );

  QF_STACK_CATCH
}

JNIEXPORT jboolean JNICALL Java_quickfix_DataDictionary_isGroup
( JNIEnv *pEnv, jobject obj, jstring msg, jint group )
{ QF_STACK_TRY

  JVM::set( pEnv );
  JVMObject jobject( obj );
  FIX::DataDictionary* pDataDictionary = ( FIX::DataDictionary* ) jobject.getInt( "cppPointer" );
  const char* umsg = pEnv->GetStringUTFChars( msg, 0 );
  std::string msgString( umsg );
  pEnv->ReleaseStringUTFChars( msg, umsg );
  return pDataDictionary->isGroup( msgString, group );

  QF_STACK_CATCH
}

