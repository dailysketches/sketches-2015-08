#include "ofApp.h"
/* Begin description
{
    Schottkey 7th Path
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(70);
    gif.fadeInOut(3, 2);

    numLayers = 1;
    masker.setup(numLayers, ISOLATE_LAYERS);
    masker.toggleOverlay();
    
    img1.setup("pcb-bw.png");
    
    horizontalMasks.setup(200, gif.height);
    
    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    masker.beginLayer(0);
    {
        ofBackground(ofColor::black);
        horizontalMasks.draw();
    }
    masker.endLayer(0);
    
    masker.beginMask(0);
    {
        ofBackground(ofColor::black);
        img1.incrementTextureOffsetY(-0.2);
        img1.draw();
    }
    masker.endMask(0);
}

void ofApp::draw(){
    gif.begin();
    {
        ofEnableAlphaBlending();
        ofBackground(ofColor::black);
        masker.draw();
    }
    gif.endCaptureDraw();
    masker.drawOverlay();
}

void MaskArray::setup(int _number, float _size) {
    number = _number;
    size = _size;
    unitSize = size / number;
    
    for(int i = 0; i < size; i++) {
        alphas.push_back(ofRandom(255));
        speeds.push_back(ceil(ofRandom(6)) * 30);
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

    if(alphas.at(i) > 255) {
        alphas.at(i) = 255;
        directions.at(i) = -1;
    }
}
/* Snippet end */

void MaskArray::debug() {
    for(int i = 0; i < number; i++) {
        cout << i << " " << alphas.at(i) << endl;
    }
    
    cout << "=======" << endl << endl << endl;
}

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