#pragma once 

#include "ofMain.h"
#include "Particle.h"

class MSystem {

  private:
    ofxFloatSlider mMinDistanceSl, mMinRadiusSl;
    vector<Particle> *mParticleRefs;
    vector<ofMesh> meshes;
    float mGlobalMinDistancef;
    float mGlobalMinRadiusf;

  public:
    void setup(ofxPanel *pGui, vector<Particle> *pParticleRefs);
    void update();
    void draw();

    // callback 
    void onGlobalMinDistanceChange(float &pDistance);
    void onGlobalMinRadiusChange(float &pRadius);
};
