#include "ofApp.h"
/* Begin description
{
    Uncertain agenda.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(50);
    gif.fadeInOut(2, 1, ofColor::red);
    gif.enableTextOverlay();

    layerIncrement = 0.01;
    maskIncrement = 0.0005;

    numLayers = 20;
    numMasksPerLayer = 1;
    masker.setup(numLayers);

    layer.setup("rust-tall2.png");
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 0.25, 1);
        layer.setTextureScale(scale);
        layer.setTextureOffset(i % 2 == 0 ? TEXTURE_OFFSET_TOP_LEFT : TEXTURE_OFFSET_TOP_RIGHT);
        layer.setTextureOffsetY(ofRandom(2));
        layers.push_back(layer);

        maskLoader.clear();
        scale = ofMap(i, 0, numLayers-1, 0.5, 1.3);
        mask.setup("circle-feather.png", scale, TEXTURE_OFFSET_MIDDLE_CENTER);
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
            gif.rotateAroundCenter(i * 90);
            ofSetColor(ofColor(ofColor::red));
            increment = ofMap(i, 0, numLayers-1, layerIncrement, -layerIncrement);
            layers.at(i).incrementTextureScale(i % 2 == 0 ? increment : -increment * 8 );
            layers.at(i).incrementTextureOffsetX((i % 2 == 0 ? increment : -increment) * ofRandom(-2, 27));
            layers.at(i).incrementTextureOffsetY((i % 2 == 0 ? -increment : increment) * ofRandom(-2, 27));
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
                i % 2 == 0 ? masks.at(i).at(j).draw() : masker.drawLayer(i - 1, false);
            }
        }
        masker.endMask(i);
    }
}

void ofApp::draw(){
    gif.begin();
    {
        gif.rotateAroundCenter(45);
        layers.at(0).draw();
        masker.drawLayer(13);
        masker.drawLayer(16);
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