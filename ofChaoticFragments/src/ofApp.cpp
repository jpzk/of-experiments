#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetVerticalSync(true);

  // creating the GUI
  mGui.setup();
  mParSystem.setup(&mGui);
  mMeshSystem.setup(&mGui, &(mParSystem.mParticles));

  Attractor center;
  center.mPosition = ofPoint(0.0f,0.0f, 0.0f);
  center.mAttract = 0.5f;
  mAttractors.push_back(center);
  
  for(vector<Attractor>::iterator it = mAttractors.begin();
      it != mAttractors.end(); ++it) {
    mParSystem.addAttractorRef(&(*it));
  }

  rotation = 0.0f;
  ofSetFrameRate(60);

    if(ofIsGLProgrammableRenderer()){
        shader.load("shadersGL3/shader");
    }else{
        shader.load("shadersGL2/shader");
    }
}

//--------------------------------------------------------------
void ofApp::update(){
  mParSystem.update();
  mMeshSystem.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(100, 100, 100);
  ofSetColor(255, 0, 255);
  ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 300, 15);

  shader.begin();
  cam.begin();
  rotation++;
  ofRotateY(rotation);
  mParSystem.draw();
  mMeshSystem.draw();
  cam.end();
  shader.end();

  mGui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
}
