#include "ofApp.h"
/* Begin description
{
    Stop investigating texture
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setupPaused(50, 100);
    gif.fadeInOut(3, 6, ofColor::white);
    gif.enableTextOverlay();
    numLayers = 12;
    numRects = gif.width * 0.5;
    masker.setup(numLayers + 2);
    
    img.setup("pcb2.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 16, -3);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        textures.push_back(img);
    }
    
    img.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 2, 1);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        masks.push_back(img);
    }
    
    for(int i = 0; i < numRects; i++) {
        rectAlphaMultipliers.push_back(ofRandom(0.1, 0.5));
    }
    rectWidth = gif.width / numRects;
    
    ofSetWindowShape(1200, 1200);
    masker.toggleOverlay();
}

void ofApp::update(){
    for(int i = 0; i < numLayers; i++) {
        masker.beginLayer(i);
        {
            textures.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, -0.002, 0.002));
            textures.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            masks.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, -0.002, 0.002));
            masks.at(i).draw();
        }
        masker.endMask(i);
    }
    
    masker.beginLayer(numLayers);
    {
        masker.drawLayers(0, numLayers-1);
    }
    masker.endLayer(numLayers);
    
    masker.beginMask(numLayers);
    {
        ofBackground(ofColor::black);
        for(int i = 0; i < numRects; i++) {
            float alpha = sin(ofGetFrameNum() * rectAlphaMultipliers.at(i));
            alpha = ofMap(alpha, -1, 1, 0, 255);
            ofSetColor(ofColor(ofColor::white, alpha));
            ofRect(i * rectWidth, 0, rectWidth, gif.height);
        }
    }
    masker.endMask(numLayers);
    
    masker.beginLayer(numLayers + 1);
    {
        ofEnableAlphaBlending();
        masker.drawLayer(numLayers);
    }
    masker.endLayer(numLayers + 1);
}

void ofApp::draw(){
    gif.begin();
    {
        ofBackground(ofColor::white);
        masker.draw();
    }
    gif.endCaptureDraw();
    masker.drawOverlay();
}
/* Snippet end */

void ofApp::keyPressed(int key){
    if(key == 'o') {
        masker.toggleOverlay();
    }
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y ){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){
    
}