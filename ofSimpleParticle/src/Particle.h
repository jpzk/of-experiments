#pragma once

#include "ofMain.h"

class Particle {

  private:
    float *mGlobalDampingf;
    float *mGlobalAttractf;
    ofMesh mMesh;

  public:
    ofPoint pos, vel, frc;

    void setInitialCondition(ofPoint pPos, ofPoint pVel);
    void setGlobalRefs(float *pDamping, float *pAttraction);
    void resetForce();
    void addAttractionForce(ofPoint pPos, float pAttract); 
    void update();
    void draw();
};


