/*
Generic implementation of the AdmobAds extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "AdmobAds_internal.h"
s3eResult AdmobAdsInit()
{
    //Add any generic initialisation code here
    return AdmobAdsInit_platform();
}

void AdmobAdsTerminate()
{
    //Add any generic termination code here
    AdmobAdsTerminate_platform();
}

s3eResult InitAds(const char* pub_id)
{
	return InitAds_platform(pub_id);
}

s3eResult ShowAds()
{
	return ShowAds_platform();
}

s3eResult HideAds()
{
	return HideAds_platform();
}
