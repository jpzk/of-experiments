#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "Attractor.h"
#include "Particle.h"

/**
 * This class defines a particle system, which many 
 * object particles belong to. You can add attraction 
 * forces via Attractor objects. 
 */
class PSystem {

  private:
    ofxFloatSlider mAttractSl, mDampingSl;
    vector<Particle> mParticles;
    vector<Attractor*> mAttractorRefs;
    float mGlobalAttractf, mGlobalDampingf;

  public:
    void setup(ofxPanel *pGui);
	void addAttractorRef(Attractor *pAttractor);
    void update();
	void draw();

    // callbacks
    void onAttractionChange(float &pAttract);
    void onDampingChange(float &pDamping);
};


