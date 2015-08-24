#include "ofApp.h"
/* Begin description
{
    Negative space.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    numLayers = 50;
    ofSetWindowShape(500, 500);
    gif.setup(100);
    masker.setup(numLayers, ISOLATE_LAYERS);
    masker.toggleOverlay();
    ofEnableSmoothing();
    ofSetWindowShape(1000, 1200);
}

void ofApp::update(){
    for(int i = 0; i < numLayers; i++) {
        masker.beginMask(i);
        {
            color = ofRandom(1) > 0.5 ? ofColor::white : ofColor::black;
            ofBackground(color);
        }
        masker.endMask(i);
        
        masker.beginLayer(i);
        {
            ofBackground(ofColor(ofColor::white, 0));
            size = ofMap(i, 0, numLayers, gif.doubleWidth, 330);
            if(i % 2 == 0) {
                ofSetColor(ofColor(ofColor::red, 100));
                size *= 0.8;
            } else {
                ofSetColor(ofColor::black);
            }
            gif.rotateAroundCenter(ofRandom(360));
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofRect(gif.halfWidth, gif.halfHeight, size, size);
            ofSetRectMode(OF_RECTMODE_CORNER);
            
        }
        masker.endLayer(i);
    }
}

void ofApp::draw(){
    gif.begin();
    {
        ofSetColor(ofColor(ofColor::white, 100));
        ofRect(0, 0, gif.width, gif.height);
        masker.draw();

        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(ofColor(ofColor::black, 210));
        ofRect(gif.halfWidth, gif.halfHeight, 360, 360);
        ofSetColor(ofColor::white);
        ofRect(gif.halfWidth, gif.halfHeight, 20, 20);
        ofSetRectMode(OF_RECTMODE_CORNER);
    }
    gif.endCaptureDraw();
    masker.drawOverlay();
}
/* Snippet end */

void ofApp::keyPressed(int key){
    if(key == 'o'){
        masker.toggleOverlay();
    }
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