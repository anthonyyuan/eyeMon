#include <jni.h>
#include <string.h>
#include <stdio.h>
#include <android/log.h>


#define DEBUG_TAG "NDK_AndroidNDK1SampleActivity"








/// old testy
void Java_org_opencv_samples_facedetect_FdActivity_helloLog(JNIEnv * env, jobject this, jstring logThis)
{
        jboolean isCopy;
        const char * szLogThis = (*env)->GetStringUTFChars(env, logThis, &isCopy);

        __android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG, "NDK:LC: [%s]", szLogThis);

        (*env)->ReleaseStringUTFChars(env, logThis, szLogThis);
}

jstring Java_org_opencv_samples_facedetect_FdActivity_getString(JNIEnv * env, jobject this, jint value1, jint value2)
{
        char *szFormat = "The sum of the two numbers is: %i";
        char *szResult;

        // add the two values
        jlong sum = value1+value2;

        // malloc room for the resulting string
        szResult = malloc(sizeof(szFormat) + 20);

        // standard sprintf
        sprintf(szResult, szFormat, sum);

        // get an object string
        jstring result = (*env)->NewStringUTF(env, szResult);

        // cleanup
        free(szResult);

        return result;
}
