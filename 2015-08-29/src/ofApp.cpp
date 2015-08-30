#include "ofApp.h"
/* Begin description
{
    Masking 2015-08-27 with 2015-08-28
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(50);
    gif.fadeInOut(3, 6, ofColor::white);
    gif.enableTextOverlay();
    pattern1.setup(&gif);
    pattern2.setup(&gif);
    masker.setupSingleLayer();
    masker.toggleOverlay();
    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    pattern1.update();
    pattern2.update();

    masker.beginLayer();
    {
        pattern2.draw();
    }
    masker.endLayer();

    masker.beginMask();
    {
        gif.rotateAroundCenter(180);
        pattern1.draw();
    }
    masker.endMask();
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

void Pattern1::setup(ofxGifEncoderTemplate *_gif) {
    gif = _gif;
    numLayers = 5;
    numRects = gif->width * 0.5;
    masker.setup(numLayers + 1);
    
    img.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 16, -3);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        textures.push_back(img);
    }
    
    img.setup("pcb2.png", 1.0, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 2, 1);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        masks.push_back(img);
    }
    
    for(int i = 0; i < numRects; i++) {
        rectAlphaMultipliers.push_back(ofRandom(0.1, 0.5));
    }
    rectWidth = gif->width / numRects;
}

void Pattern1::update() {
    for(int i = 0; i < numLayers; i++) {
        masker.beginLayer(i);
        {
            textures.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, -0.001, 0.002));
            textures.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            masks.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, -0.001, 0.009));
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
            ofRect(i * rectWidth, 0, rectWidth, gif->height);
        }
    }
    masker.endMask(numLayers);
}

void Pattern1::draw() {
    ofBackground(ofColor::white);
    masker.draw();
    for(int i = 0; i < 3; i++) {
        masker.drawLayer(numLayers);
    }
    masker.drawOverlay();
}

void Pattern2::setup(ofxGifEncoderTemplate *_gif) {
    gif = _gif;
    numLayers = 3;
    numRects = gif->width * 0.5;
    masker.setup(numLayers);
    
    img.setup("pcb2.png", 1.0, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 16, 5);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        textures.push_back(img);
    }
    
    img.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 4, 1);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        masks.push_back(img);
    }
    
    for(int i = 0; i < numRects; i++) {
        rectAlphaMultipliers.push_back(ofRandom(0.1, 0.5));
    }
    rectWidth = gif->width / numRects;
}

void Pattern2::update() {
    for(int i = 0; i < numLayers; i++) {
        masker.beginLayer(i);
        {
            ofSetColor(ofColor::white);
            textures.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, -0.002, 0.002));
            textures.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            ofSetColor(ofColor::white);
            masks.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, -0.002, 0.002));
            masks.at(i).draw();
        }
        masker.endMask(i);
    }
}

void Pattern2::draw() {
    ofBackground(ofColor::white);
    masker.draw();
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