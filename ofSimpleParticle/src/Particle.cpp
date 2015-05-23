#include "ofApp.h"
#include "Particle.h"

/**
 * This class defines a Particle of the PSystem
 */
Particle::Particle() { 
}

/**
 * This method is used in the setup of the particle
 * to set its initial values
 */
void Particle::setInitialCondition(ofPoint pPos, ofPoint 
    pVel) {
  pos = pPos;
  vel = pVel;

  mMesh.setMode(OF_PRIMITIVE_POINTS);
  ofColor color(0.5f, 1.0f, 1.0f, 0.5f);
  mMesh.addVertex(pPos);
}

void Particle::setGlobalRefs(float *pDamping, float *pAttraction) {
  mGlobalDampingf = pDamping;
  mGlobalAttractf = pAttraction;
}

/**
 * Add a specific attraction force to the particle 
 */
void Particle::addAttractionForce(ofPoint pPos, 
    float pAttract) {

  float n = 10.0 / ofGetFrameRate();
  ofPoint v = pPos - pos;
  ofPoint normed = v / v.length();
  frc = (*mGlobalAttractf) * pAttract * normed * n;
}

/**
 * Update the particle
 */
void Particle::update() {
  vel = vel + frc;
  pos = pos + vel - ((*mGlobalDampingf) * vel);
}

/**
 * Draw the particle
 */
void Particle::draw() { 
  ofPushMatrix();
  ofTranslate(pos.x, pos.y, pos.z);
  mMesh.draw();
  ofPopMatrix();
}

