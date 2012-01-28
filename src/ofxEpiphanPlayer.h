/*
 *  ofxEpiphanPlayer.h
 *  ofxEpiphanExample
 *
 *  Created by jason van cleave on 1/28/12.
 *  Copyright 2012 jasonvancleave.com. All rights reserved.
 *
 */
#include "ofMain.h"
#include "frmgrab.h"
#include "v2u_lib.h"

typedef struct ContextOptions 
{
    V2URect cropRect;           /* Crop rectangle */
    V2U_UINT32 captureFlags;    /* Capture format and flags */
    V2U_UINT32 frameCount;      /* Frame count */
    V2U_BOOL noStreaming;       /* Streaming flag */
    V2U_BOOL actionPerformed;   /* Something meaningful has been done */
} ContextOptions;


class ofxEpiphanPlayer
{
public:
	ofxEpiphanPlayer();
	~ofxEpiphanPlayer();
	
	void setup(int width, int height);
	void update();
	void draw();
	void close();
	
	FrmGrabber* frameGrabber;
	V2U_GrabFrame2* frame;
	ContextOptions options;
	ofImage image;
	
	int videoWidth;
	int videoHeight;
	
	int status;
};