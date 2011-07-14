/*
Internal header for the AdmobAds extension.

This file should be used for any common function definitions etc that need to
be shared between the platform-dependent and platform-indepdendent parts of
this extension.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef ADMOBADS_H_INTERNAL
#define ADMOBADS_H_INTERNAL

#include "s3eTypes.h"
#include "AdmobAds.h"
#include "AdmobAds_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult AdmobAdsInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult AdmobAdsInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void AdmobAdsTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void AdmobAdsTerminate_platform();
s3eResult InitAds_platform(const char* pub_id);

s3eResult ShowAds_platform();

s3eResult HideAds_platform();


#endif /* ADMOBADS_H_INTERNAL */