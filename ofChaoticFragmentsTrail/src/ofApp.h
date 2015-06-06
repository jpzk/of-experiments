#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxFastFboReader.h"

#include "Attractor.h"
#include "PSystem.h"
#include "MSystem.h"

class ofApp : public ofBaseApp{
  private:
    MSystem mMeshSystem;
    PSystem mParSystem;

    bool mIsParticlesDrawn;
    int mFrameCount;
    int mAlpha;
    ofImage texture;
    ofFbo fbo;
    ofxPanel mGui;
    ofxIntSlider alpha;
    ofxFastFboReader mFboReader;
    ofImage mScreenshot;
    ofPixels mPixel;
    vector<Attractor> mAttractors;
    ofEasyCam cam;
    float rotation;
    ofShader shader;

    void alphaChanged(int &pAlpha);

  public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};

