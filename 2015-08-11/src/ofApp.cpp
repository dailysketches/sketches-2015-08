#include "ofApp.h"
/* Begin description
{
    Consumption.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setupPaused(ofGetTimestampString("out/%Y-%m-%d"), 50, 100);
    gif.fadeInOut(3, 6, ofColor::white);
    gif.enableTextOverlay();
    numTissues = 16;
    numRoads = 8;
    masker.setup(numRoads);

    road.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numRoads; i++) {
        scale = ofMap(i, 0, numRoads-1, 3, 1.0);
        road.setTextureScale(scale);
        road.setTextureOffsetY(ofRandom(2));
        roads.push_back(road);

        tissuesLoader.clear();
        scale = ofMap(i, 0, numRoads-1, 8, 0.5);
        tissue.setup("tissue.png", scale, TEXTURE_OFFSET_MIDDLE_CENTER);
        tissue.incrementTextureOffsetX(-0.5);
        tissue.setTextureOffsetY(ofRandom(2));
        for(int j = 0; j < numTissues; j++) {
            tissuesLoader.push_back(tissue);
        }
        tissues.push_back(tissuesLoader);
    }
}

void ofApp::update(){
    for(int i = 0; i < numRoads; i++) {
        masker.beginLayer(i);
        {
            float others = ofMap(i, 0, numRoads-1, 100, 255);
            ofSetColor(ofColor(255, others, others, others));
            roads.at(i).incrementTextureOffsetY(ofMap(i, 0, numRoads-1, 0.008, -0.002));
            roads.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            ofSetColor(ofColor::white);
            ofBackground(ofColor::white);
            for(int j = 0; j < tissues.size(); j++) {
                tissues.at(i).at(j).incrementTextureOffsetY((j+1) * ofMap(i, 0, numRoads-1, 0.0032, -0.0032));
                tissues.at(i).at(j).draw();
            }
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