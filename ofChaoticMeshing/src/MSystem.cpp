#include "ofMain.h"
#include "ofxGui.h"
#include "MSystem.h"

void MSystem::setup(ofxPanel *pGui, vector<Particle> *pParticleRefs) {

  mGlobalMinDistancef = 75.0f;
  mGlobalMinRadiusf = 35.0f;

  mMinDistanceSl.addListener(this, &MSystem::onGlobalMinDistanceChange);
  pGui->add(mMinDistanceSl.setup("mindistance", mGlobalMinDistancef, 
        0.0f, 1000.0f)); 
 
  mMinRadiusSl.addListener(this, &MSystem::onGlobalMinRadiusChange);
  pGui->add(mMinRadiusSl.setup("minradius", mGlobalMinRadiusf, 
        0.0f, 1000.0f)); 
  
  mParticleRefs = pParticleRefs;
}

void MSystem::update() { 

  meshes.clear();
  int currentMesh = 0;
  int maxPerMesh = 3;
  ofMesh *mesh;
  vector<ofPoint> points;

  for(vector<Particle>::iterator p1 = mParticleRefs->begin();
      p1 != mParticleRefs->end();
      ++p1) {
 
    currentMesh = 1;
    points.push_back(p1->pos);

    for(vector<Particle>::iterator p2 = mParticleRefs->begin();
        p2 != mParticleRefs->end();
        ++p2) {
      if(currentMesh == maxPerMesh) {
        break;
      }

      if(p1 != p2) {
        ofPoint pv1 = p1->pos;
        ofPoint pv2 = p2->pos;
        float dist = abs((pv1 - pv2).length());
        float distToCenter = abs((pv2 - ofPoint(0.0f, 0.0f, 0.0f)).length());
        float distC = mGlobalMinDistancef;
        float radiusC = mGlobalMinRadiusf;
        if(dist < distC && distToCenter > radiusC) {
          points.push_back(p2->pos);
          currentMesh++;
        } 
      }
    }

    if(points.size() > 2) {
      mesh = new ofMesh();
      for(vector<ofPoint>::iterator it = points.begin();
          it != points.end();
          ++it) { 
        mesh->addVertex((*it));
        meshes.push_back(*mesh);
      }
    }
    points.clear();
  }
}

void MSystem::draw() {
  for(vector<ofMesh>::iterator it = meshes.begin();
      it != meshes.end(); ++it) {
    (*it).draw();
  }
}

void MSystem::onGlobalMinDistanceChange(float &pDistance) {
  mGlobalMinDistancef = pDistance;
}

void MSystem::onGlobalMinRadiusChange(float &pRadius) {
  mGlobalMinRadiusf = pRadius;
}
