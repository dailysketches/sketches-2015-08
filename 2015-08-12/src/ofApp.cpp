#include "ofApp.h"
/* Begin description
{
    The center of your body.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(ofGetTimestampString("out/%Y-%m-%d"), 50);
    gif.fadeInOut(3, 6, ofColor::white);
    gif.enableTextOverlay();
    numTissues = 16;
    numRoads = 16;
    masker.setup(numRoads);

    road.setup("glass3.png");
    for(int i = 0; i < numRoads; i++) {
        scale = ofMap(i, 0, numRoads-1, 4, 2.5);
        road.setTextureScale(scale);
        road.setTextureOffset(i % 2 == 0 ? TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER : TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
        road.setTextureOffsetY(ofRandom(2));
        roads.push_back(road);

        tissuesLoader.clear();
        scale = ofMap(i, 0, numRoads-1, 8, 1.5);
        tissue.setup("tissue.png", scale, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
        for(int j = 0; j < numTissues; j++) {
            tissue.setTextureOffsetY(ofRandom(2));
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
            ofSetColor(ofColor(others, others, others, others));
            roads.at(i).incrementTextureOffsetY(ofMap(i, 0, numRoads-1, -0.001, 0.001));
            roads.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            ofSetColor(ofColor::white);
            ofBackground(ofColor::white);
            for(int j = 0; j < tissues.size(); j++) {
                tissues.at(i).at(j).incrementTextureOffsetY((j+1) * ofMap(i, 0, numRoads-1, 0.0002, -0.0002));
                tissues.at(i).at(j).draw();
            }
        }
        masker.endMask(i);
    }
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