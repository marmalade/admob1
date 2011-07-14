/*
 * android-specific implementation of the AdmobAds extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "AdmobAds_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_InitAds;
static jmethodID g_ShowAds;
static jmethodID g_HideAds;

s3eResult AdmobAdsInit_platform()
{
    //Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    //Get the extension class
    jclass cls = s3eEdkAndroidFindClass("AdmobAds");
    if (!cls)
        goto fail;

    //Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    //Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    //Get all the extension methods
    g_InitAds = env->GetMethodID(cls, "InitAds", "(Ljava/lang/String;)I");
    if (!g_InitAds)
        goto fail;

    g_ShowAds = env->GetMethodID(cls, "ShowAds", "()I");
    if (!g_ShowAds)
        goto fail;

    g_HideAds = env->GetMethodID(cls, "HideAds", "()I");
    if (!g_HideAds)
        goto fail;



    IwTrace(ADMOBADS, ("ADMOBADS init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteLocalRef(cls);
    
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
    
fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(AdmobAds, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void AdmobAdsTerminate_platform()
{
    // Add any platform-specific termination code here
}

s3eResult InitAds_platform(const char* pub_id)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring pub_id_jstr = env->NewStringUTF(pub_id);
    return (s3eResult)env->CallIntMethod(g_Obj, g_InitAds, pub_id_jstr);
}

s3eResult ShowAds_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_ShowAds);
}

s3eResult HideAds_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_HideAds);
}
