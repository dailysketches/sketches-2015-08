#include "ofApp.h"
/* Begin description
{
    Mask yourself.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setupPaused(130, 176);
    gif.fadeInOut(3, 2, ofColor::white);

    masker.setup(1, ISOLATE_LAYERS);
    masker.toggleOverlay();

    img2.setup("glass3.png", 0.2);
    img1.setup("pcb-bw.png", 2.0);

    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    masker.beginLayer();
    {
        img1.draw();
    }
    masker.endLayer();
    
    masker.beginMask();
    {
        img1.draw();
    }
    masker.endMask();
}

void ofApp::draw(){
    gif.begin();
    {
        ofEnableAlphaBlending();
        img2.incrementTextureScale(0.006);

        masker.draw();
        if(ofRandom(1) > 0.75) {
            ofSetColor(ofColor::white, 255);
            gif.rotateAroundCenter(90 * floor(ofRandom(4)));

            for(int i = 0; i < ofRandom(2, 10); i++) {
                masker.draw();
            }
        } else if(ofRandom(1) > 0.75) {
            img1.setTexturePosition(ofRandom(2), ofRandom(2));
            img1.setTextureScale(ofRandom(0.2, 2));
            img2.setTextureScale(ofRandom(1, 3));
            gif.rotateAroundCenter(90 * floor(ofRandom(4)));
            ofSetColor(ofColor::white, ofRandom(10, 20));
            img1.draw();
        }
        ofSetColor(ofColor::white, ceil(ofRandom(6)) * 6);
        img2.draw();
    }
    gif.endCaptureDraw();
    masker.drawOverlay();
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