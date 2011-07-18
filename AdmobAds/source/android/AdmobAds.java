/*
java implementation of the AdmobAds extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import android.view.ViewGroup.LayoutParams;
import android.view.View;

import com.google.ads.Ad;
import com.google.ads.AdRequest;
import com.google.ads.AdRequest.ErrorCode;
import com.google.ads.AdSize;
import com.google.ads.AdView;
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;

class AdmobAds
{
    private static final int ADVIEW_NOT_INITIALIZED = 1;
    private AdView adView;

    public int InitAds(final String pub_id)
    {
	LoaderActivity.m_Activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				adView = new AdView(LoaderActivity.m_Activity, AdSize.BANNER, pub_id);
				adView.loadAd(new AdRequest());
				LoaderActivity.m_Activity.addContentView(adView, new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
			}
		});
        return 0;
    }
    public int ShowAds()
    {
	if(adView!=null){
		LoaderActivity.m_Activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				adView.setVisibility(View.VISIBLE);
			}});
	} else { 
		return ADVIEW_NOT_INITIALIZED; 
	}

        return 0;
    }
    public int HideAds()
    {
	if(adView!=null){
		LoaderActivity.m_Activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				adView.setVisibility(View.INVISIBLE);
			}});
	} else { 
		return ADVIEW_NOT_INITIALIZED; 
	}
        return 0;
    }

}
