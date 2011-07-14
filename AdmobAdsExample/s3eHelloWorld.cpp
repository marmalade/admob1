/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * Copyright (C) 2001-2011 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This source code is intended only as a supplement to Ideaworks Labs
 * Development Tools and/or on-line documentation.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */

/**
 * @page ExampleS3EHelloWorld S3E Hello World Example
 *
 * The following example, in typical Hello World style, displays the phrase
 * "Hello, World!" on screen.
 *
 * The functions required to achieve this are:
 * Printing the text to screen:
 * <ul>
 *   <li>s3eDebugPrint()
 * </ul
 *
 * Handling the text:
 * <ul>
 *   <li>s3eDeviceCheckQuitRequest()
 *   <li>s3eSurfaceClear()
 *   <li>s3eSurfaceShow()
 * </ul>
 *
 * All examples will follow this basic pattern; a brief description of what
 * the example does will be given followed by a list of all the important
 * functions and, perhaps, classes.
 *
 * Should the example be more complex, a more detailed explanation of what the
 * example does and how it does it will be added. Note that most examples
 * use an example framework to remove boilerplate code and allow the projects
 * to be made up of a single source file for easy viewing. This framework can
 * be found in the examples/s3e/ExamplesMain directory.
 *
 * @include s3eHelloWorld.cpp
 */
#include "s3e.h"
#include "AdmobAds.h"
// Main entry point for the application
int main()
{
	int i = 0;
	bool hidden = false;
	bool adsAvailable = false;
	bool noView = false;

	if(AdmobAdsAvailable()){
		InitAds("a14bd815ee70598");
		adsAvailable = true;
	}

		
    // Wait for a quit request from the host OS
    while (!s3eDeviceCheckQuitRequest())
    {
        

		// Fill background blue
        s3eSurfaceClear(0, 0, 255);

        // Print a line of debug text to the screen at top left (0,0)
        // Starting the text with the ` (backtick) char followed by 'x' and a hex value
        // determines the colour of the text.
        s3eDebugPrint(120, 150, "`xffffffHello, World!", 0);

		if (noView){
			s3eDebugPrint(120, 190, "`xff1111No view", 0);
		}else{
			s3eDebugPrint(120, 190, "`x11ff11Ok", 0);
		}

        // Flip the surface buffer to screen
        s3eSurfaceShow();

        // Sleep for 0ms to allow the OS to process events etc.
        s3eDeviceYield(1);

		if(adsAvailable){
			i++;

			if(i>15000){
				i = 0;
				if (hidden) {
					noView = ShowAds() != 0;
				} else {
					noView = HideAds() != 0;
				}

				hidden = !hidden;
			}
		}

		s3eKeyboardUpdate();
		if(s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_DOWN){
			break;
		}
    }
    return 0;
}
