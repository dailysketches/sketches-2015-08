#include "ofApp.h"
/* Begin description
{
    Blood work.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(ofGetTimestampString("out/%Y-%m-%d"), 50);
    gif.fadeInOut(2, 1, ofColor::red);
    gif.enableTextOverlay();

    layerIncrement = 0.005;
    maskIncrement = 0.0002;

    numLayers = 32;
    numMasksPerLayer = 6;
    masker.setup(numLayers);

    layer.setup("glass3.png");
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 4, 2.5);
        layer.setTextureScale(scale);
        layer.setTextureOffset(i % 2 == 0 ? TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER : TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
        layer.setTextureOffsetY(ofRandom(2));
        layers.push_back(layer);

        maskLoader.clear();
        scale = ofMap(i, 0, numLayers-1, 6, 0.33);
        mask.setup("tissue.png", scale, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
        for(int j = 0; j < numMasksPerLayer; j++) {
            mask.setTextureOffsetY(ofRandom(2));
            maskLoader.push_back(mask);
        }
        masks.push_back(maskLoader);
    }

    ofSetWindowShape(1000, 1200);
    masker.toggleOverlay();
}

void ofApp::update(){
    for(int i = 0; i < numLayers; i++) {
        masker.beginLayer(i);
        {
            ofSetColor(ofColor(ofColor::red));
            increment = ofMap(i, 0, numLayers-1, layerIncrement, -layerIncrement);
            layers.at(i).incrementTextureOffsetY(increment);
            layers.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            ofSetColor(ofColor::white);
            ofBackground(ofColor::white);
            for(int j = 0; j < numMasksPerLayer; j++) {
                increment = (j+1) * ofMap(i, 0, numLayers-1, maskIncrement, -maskIncrement);
                masks.at(i).at(j).incrementTextureOffsetY(increment);
                masks.at(i).at(j).draw();
            }
        }
        masker.endMask(i);
    }
}

void ofApp::draw(){
    gif.begin();
    {
        ofSetColor(ofColor(ofColor::red));
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