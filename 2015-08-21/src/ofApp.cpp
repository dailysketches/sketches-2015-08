#include "ofApp.h"
/* Begin description
{
    MARCHROMT30a Edit 2b 96
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setupPaused(14, 48);
    gif.fadeInOut(3, 2);

    numLayers = 2;
    masker.setup(numLayers, ISOLATE_LAYERS);
    masker.toggleOverlay();
    
    img1.setup("glass3.png", 0.2);
    img2.setup("pcb-bw.png", 6.0);
    
    horizontalMasks.setup(10, gif.height);
    verticalMasks.setup(3, gif.width);
    
    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    masker.beginLayer(0);
    {
        ofBackground(ofColor::black);
        img1.incrementTextureOffsetY(-0.02);
        img1.incrementTextureScale(0.006);
        img1.draw();
    }
    masker.endLayer(0);
    
    masker.beginMask(0);
    {
        ofBackground(ofColor::black);
        horizontalMasks.draw();
        gif.rotateAroundCenter(90);
        verticalMasks.draw();
    }
    masker.endMask(0);

    masker.beginLayer(1);
    {
        masker.drawLayer(0);
    }
    masker.endLayer(1);
    
    masker.beginMask(1);
    {
        masker.drawLayer(0);
    }
    masker.endMask(1);
}

void ofApp::draw(){
    gif.begin();
    {
        ofEnableAlphaBlending();
        img2.incrementTextureOffsetY(0.002);
        img2.incrementTextureScale(-0.006);

        masker.drawLayer(1);
        ofSetColor(ofColor::white, ceil(ofRandom(6)) * 3);
        img2.draw();
    }
    gif.endCaptureDraw();
    masker.drawOverlay();
}

void MaskArray::setup(int _number, float _size) {
    number = _number;
    size = _size;
    unitSize = size / number;
    
    for(int i = 0; i < size; i++) {
        alphas.push_back(ofRandom(24));
        speeds.push_back(ceil(ofRandom(3)));
        directions.push_back(ofRandom(1) > 0.5 ? 1 : -1);
    }
}

void MaskArray::draw() {
    for(int i = 0; i < number; i++) {
        alphas.at(i) += speeds.at(i) * directions.at(i);
        bounce(i);
        ofSetColor(ofColor(ofColor::white, alphas.at(i)));
        ofRect(0, unitSize * i, size, unitSize);
    }
}

void MaskArray::bounce(int i) {
    if(alphas.at(i) < 0) {
        alphas.at(i) = 0;
        directions.at(i) = 1;
    }

    if(alphas.at(i) > 24) {
        alphas.at(i) = 24;
        directions.at(i) = -1;
    }
}

void MaskArray::debug() {
    for(int i = 0; i < number; i++) {
        cout << i << " " << alphas.at(i) << endl;
    }
    
    cout << "=======" << endl << endl << endl;
}
/* Snippet end */

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y){

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