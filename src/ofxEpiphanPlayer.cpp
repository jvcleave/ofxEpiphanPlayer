/*
 *  ofxEpiphanPlayer.cpp
 *  ofxEpiphanExample
 *
 *  Created by jason van cleave on 1/28/12.
 *  Copyright 2012 jasonvancleave.com. All rights reserved.
 *
 */

#include "ofxEpiphanPlayer.h"

ofxEpiphanPlayer::ofxEpiphanPlayer()
{
	ofDisableArbTex();
	frameGrabber = NULL;
	frame = NULL;
}


void ofxEpiphanPlayer::setup(int width, int height)
{
	videoWidth = width;
	videoHeight = height;
	
	image.allocate(videoWidth, videoHeight, OF_IMAGE_COLOR);
	
	options.captureFlags = V2U_GRABFRAME_FORMAT_RGB24;
	options.cropRect.x = 0;
	options.cropRect.y = 0;
	options.cropRect.width = videoWidth;
	options.cropRect.height = videoHeight;
	FrmGrabNet_Init();
	frameGrabber = FrmGrabLocal_Open();
}

void ofxEpiphanPlayer::update()
{
	if (frameGrabber != NULL)
	{
		frame = FrmGrab_Frame(frameGrabber, options.captureFlags, &options.cropRect);
		if (frame) 
		{
			image.setFromPixels((unsigned char *)frame->pixbuf,  videoWidth,  videoHeight,  OF_IMAGE_COLOR);
			FrmGrab_Release(frameGrabber, frame);
		}
	} else
	{
		ofLogError("no frame grabbers found");
	}
	
}

void ofxEpiphanPlayer::draw()
{
	image.draw(0, 0, videoWidth, videoHeight);
}

void ofxEpiphanPlayer::close()
{
	if (frameGrabber != NULL)
	{
		FrmGrab_Close(frameGrabber);
	}
}

ofxEpiphanPlayer::~ofxEpiphanPlayer()
{
	close();
}