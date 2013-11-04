//
//  ofxAVFVideoPlayer.h
//  AVFoundationTest
//
//  Created by Sam Kronick on 5/31/13.
//
//

#pragma once

#include "ofMain.h"

#ifdef __OBJC__
#import "ofxAVFVideoRenderer.h"
#endif


class ofxAVFVideoPlayer  : public ofBaseVideoPlayer {
public:
    
    ofxAVFVideoPlayer();
    ~ofxAVFVideoPlayer();
    
    bool                loadMovie(string path);
    
    void                closeMovie();
    void                close();
    
    void                idleMovie();
    void                update();
    void                play();
    void                stop();
#if __MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_7 /*deplyment target needs to be 10.8 or bigger for this to work!*/
    float               getAmplitude(int channel = 0);
    float               getAmplitudeAt(float pos, int channel = 0);
    float *             getAllAmplitudes();
    int                 getNumAmplitudes();
#endif
	
    OF_DEPRECATED_MSG("Use getTexture()->bind() instead. Ensure decodeMode != OF_QTKIT_DECODE_PIXELS_ONLY.", void bind());
    OF_DEPRECATED_MSG("Use getTexture()->unbind() instead. Ensure decodeMode != OF_QTKIT_DECODE_PIXELS_ONLY.", void unbind());
    
    bool                isFrameNew(); //returns true if the frame has changed in this update cycle
    
    // Returns openFrameworks compatible RGBA pixels.
    // Be aware of your current render mode.
    
    unsigned char * getPixels();
    ofPixelsRef     getPixelsRef();
    
    // Returns openFrameworks compatible ofTexture pointer.
    // if decodeMode == OF_QTKIT_DECODE_PIXELS_ONLY,
    // the returned pointer will be NULL.
    ofTexture * getTexture();
    ofTexture& getTextureReference();
    
    float               getPosition();
    float               getPositionInSeconds();
    float               getSpeed();
    ofLoopType          getLoopState();
    float               getDuration();
    bool                getIsMovieDone();
    int                 getTotalNumFrames();
    int                 getCurrentFrame();
    
    void                setPaused(bool _bPaused);
    void                setPosition(float pct);
	void                setPositionInSeconds(float seconds);
    void                setVolume(float volume);
    void                setBalance(float balance);
    void                setLoopState(ofLoopType state);
    void                setSpeed(float _speed);
    void                setFrame(int frame); // frame 0 = first frame...
    
    // ofQTKitPlayer only supports OF_PIXELS_RGB and OF_PIXELS_RGBA.
    bool                setPixelFormat(ofPixelFormat pixelFormat);
    ofPixelFormat       getPixelFormat();
    
    void                draw(float x, float y, float w, float h);
    void                draw(float x, float y);
    
    float               getWidth();
    float               getHeight();
    
    bool                isPaused();
    bool                isLoaded();
    bool                isLoading();
	bool				isReady();
    bool                isPlaying();
    bool                errorLoading();
    bool                isAudioLoaded();    
    
    void                firstFrame();
    void                nextFrame();
    void                previousFrame();
    
protected:
    
    ofLoopType currentLoopState;
    
    bool bPaused;
	bool bShouldPlay;
	
	float scrubToTime;
    bool bNewFrame;
    bool bHavePixelsChanged;
    
    float duration;
    float speed;
    
    string moviePath;
    
    bool bInitialized;
    void exit(ofEventArgs& args);
    
    // updateTexture() pulls texture data from the movie AVFoundation
    // renderer into our internal ofTexture.
    void updateTexture();
    void reallocatePixels();
    
    ofFbo fbo;
    ofTexture tex;
    
    ofPixels pixels;
    ofPixelFormat pixelFormat;
    
    // This #ifdef is so you can include this .h file in .cpp files
    // and avoid ugly casts in the .m file
#ifdef __OBJC__
    AVFVideoRenderer* moviePlayer;
#else
    void * moviePlayer;
#endif
    
};
