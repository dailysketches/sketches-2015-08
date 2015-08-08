#include "ofApp.h"
/* Begin description
{
    In sharper focus.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setupPaused(ofGetTimestampString("out/%Y-%m-%d"), 50, 100);
    gif.fadeInOut(3, 6, ofColor::white);
    gif.enableTextOverlay();
    numRoads = 4;
    masker.setup(numRoads + 1);
    
    road.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numRoads; i++) {
        scale = ofMap(i, 0, numRoads-1, 0.125, 10);
        road.setTextureScale(scale);
        road.setTextureOffsetY(ofRandom(2));
        road1s.push_back(road);
    }
    
    road.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
    for(int i = 0; i < numRoads; i++) {
        scale = ofMap(i, 0, numRoads-1, 10, 0.125);
        road.setTextureScale(scale);
        road.setTextureOffsetY(ofRandom(2));
        road2s.push_back(road);
    }
}

void ofApp::update(){
    for(int i = 0; i < numRoads; i++) {
        masker.beginLayer(i);
        {
            road1s.at(i).incrementTextureOffsetY(ofMap(i, 0, numRoads-1, -0.002, 0.002));
            road1s.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            road2s.at(i).incrementTextureOffsetY(ofMap(i, 0, numRoads-1, -0.002, 0.002));
            road2s.at(i).draw();
        }
        masker.endMask(i);
    }
}

void ofApp::draw(){
    gif.begin();
    {
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