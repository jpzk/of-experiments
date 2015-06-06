#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetVerticalSync(true);

  mAlpha = 50;
  mIsParticlesDrawn = false;

  // creating the GUI
  mGui.setup();
  alpha.addListener(this, &ofApp::alphaChanged);
  mGui.add(alpha.setup("FBO alpha",10,0,255));
 
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

  texture.loadImage("glitch.png");

  fbo.allocate(ofGetWidth(),ofGetHeight(), GL_RGBA);

  // cleaning the FBO
  fbo.begin();
  ofClear(255,255,255,0);
  fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
  mParSystem.update();
  mMeshSystem.update();

  ofEnableAlphaBlending();

  // drawing into FBO
  fbo.begin();

  // fading out
  ofFill();
  ofSetColor(255,255,255, mAlpha);
  ofRect(0,0,ofGetWidth(),ofGetHeight());
  ofNoFill();
  ofSetColor(255,255,255);

  shader.begin();
  shader.setUniformTexture("image", texture.getTextureReference(), 1);

  cam.begin();
  rotation++;
  ofRotateY(rotation);
  
  if(mIsParticlesDrawn) {
    mParSystem.draw();
  }
  
  mMeshSystem.draw();
  cam.end();
  shader.end();
  fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
  fbo.draw(0,0);
  mGui.draw();
}

void ofApp::alphaChanged(int &pAlpha) {
  mAlpha = pAlpha; 
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
