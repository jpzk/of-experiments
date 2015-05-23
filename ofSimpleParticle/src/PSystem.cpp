#include "ofMain.h"
#include "ofxGui.h"

#include "PSystem.h"
#include "Particle.h"
#include "Attractor.h"

/**
 * This method sets up the particle system
 */
void PSystem::setup(ofxPanel *pGui) {

  mGlobalAttractf = 1.0f;
  mGlobalDampingf = 0.8f;

  // define callbacks for the panel, add panels to GUI
  mAttractSl.addListener(this, &PSystem::onAttractionChange);
  pGui->add(mAttractSl.setup("attraction", 1.0f, 0.0f, 
        100.0f));
  mDampingSl.addListener(this, &PSystem::onDampingChange);
  pGui->add(mDampingSl.setup("damping", mGlobalDampingf, 
        0.0f, 1.0f));

  // initializing of the particles
  int numberParticles = 3000;
  int max = 100;
  int maxV = 10;

  for(int i = 0; i < numberParticles; i++) {
    Particle *p = new Particle();

    ofPoint pos(ofRandom(-max, max),
        ofRandom(-max, max),
        ofRandom(-max, max));

    ofPoint vel(ofRandom(-maxV, maxV),
        ofRandom(-maxV, maxV),
        ofRandom(-maxV, maxV));

    p->setInitialCondition(pos, vel);
    p->setGlobalRefs(&mGlobalDampingf, &mGlobalAttractf);
    mParticles.push_back(*p);
 
    glEnable(GL_POINT_SMOOTH);
    glPointSize(4);  
  }
}

/**
 * This method allows to add an attractor reference
 * which will influence the particles
 */
void PSystem::addAttractorRef(Attractor *pAttract) {
  mAttractorRefs.push_back(pAttract);
}

/**
 * This method updates the particle system
 */
void PSystem::update() {
  for(vector<Attractor*>::iterator attr = 
      mAttractorRefs.begin(); attr != mAttractorRefs.end();
      ++attr) {

    // do the update for the particle system
    for(vector<Particle>::iterator it = mParticles.begin();
      it != mParticles.end(); ++it) {
      (*it).addAttractionForce((*attr)->mPosition,
         (*attr)->mAttract); 
    }
  }

  for(vector<Particle>::iterator it = mParticles.begin();
    it != mParticles.end(); ++it) {
    (*it).update();
  }
}

/**
 * This method draws the particle system
 */
void PSystem::draw() {
  for(vector<Particle>::iterator it = mParticles.begin();
  it != mParticles.end(); ++it) {
    (*it).draw();
  }
}

void PSystem::onAttractionChange(float &pAttract) {
  mGlobalAttractf = pAttract;
}

void PSystem::onDampingChange(float &pDamping) {
  mGlobalDampingf = pDamping;
}
