#include "ofApp.h"
/* Begin description
{
    Cutting to the core.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(ofGetTimestampString("out/%Y-%m-%d"), 47);
    gif.fadeInOut(3, 6, ofColor::white);
    gif.enableTextOverlay();
    numRoads = 7;
    increment = 0.01;
    masker.setup(numRoads);
    
    texture.setup("face-full.png", 1.0, TEXTURE_OFFSET_TOP_LEFT);
    for(int i = 0; i < numRoads; i++) {
        scale = ofMap(i, 0, numRoads-1, 0.7, 1.1);
        texture.setTextureScale(scale);
        texture.setTextureOffsetY(ofRandom(2));
        layers.push_back(texture);
    }
    
    texture.setup("tissue.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numRoads; i++) {
        scale = ofMap(i, 0, numRoads-1, 0.3, 0.5);
        texture.setTextureScale(scale);
        texture.setTextureOffsetY(ofRandom(2));
        masks.push_back(texture);
    }
}

void ofApp::update(){
    for(int i = 0; i < numRoads; i++) {
        masker.beginLayer(i);
        {
            ofSetColor(ofColor(ofColor::white, 240));
            layers.at(i).incrementTextureOffsetY(ofMap(i, 0, numRoads-1, -(increment*0.25), increment));
            layers.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            ofBackground(ofColor::white);
            masks.at(i).incrementTextureOffsetY(ofMap(i, 0, numRoads-1, increment, -(increment*0.25)));
            masks.at(i).draw();
        }
        masker.endMask(i);
    }
}

void ofApp::draw(){
    gif.begin();
    {
        ofSetColor(ofColor(ofColor::red, 180));
        layers.at(0).draw();
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