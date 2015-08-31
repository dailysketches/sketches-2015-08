#include "ofApp.h"
/* Begin description
{
    The murky underneath.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setupPaused(280, 330);
    gif.fadeInOut(2, 3, ofColor::white);
    
    pattern1.setup(&gif);
    pattern2.setup(&gif);

    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    pattern1.update();
    pattern2.update();
}

void ofApp::draw(){
    gif.begin();
    {
        ofEnableAlphaBlending();
        pattern1.draw();
        pattern2.draw();
    }
    gif.endCaptureDraw();
}

void Pattern1::setup(ofxGifEncoderTemplate *_gif) {
    gif = _gif;
    masker.setup(1, ISOLATE_LAYERS);
    masker.toggleOverlay();
    
    img1.setup("pcb-bw.png", 2.0);
    img2.setup("glass3.png", 0.2);
}

void Pattern1::update() {
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

void Pattern1::draw() {
    ofPushMatrix();
    ofEnableAlphaBlending();
    img1.incrementTextureScale(0.06);
    img2.incrementTextureScale(0.06);
    
    ofSetColor(ofColor::white, ceil(ofRandom(6)) * 13);
    img2.draw();
    
    masker.draw();
    if(ofRandom(1) > 0.75) {
        ofSetColor(ofColor::white, 255);
        gif->rotateAroundCenter(90 * floor(ofRandom(4)));
        
        for(int i = 0; i < ofRandom(2, 10); i++) {
            masker.draw();
        }
    } else if(ofRandom(1) > 0.75) {
        img1.setTexturePosition(ofRandom(2), ofRandom(2));
        img1.setTextureScale(ofRandom(0.2, 2));
        img2.setTextureScale(ofRandom(1, 3));
        gif->rotateAroundCenter(90 * floor(ofRandom(4)));
        ofSetColor(ofColor::white, ofRandom(10, 20));
        img1.draw();
    }
    ofPopMatrix();
}

void Pattern2::setup(ofxGifEncoderTemplate *_gif) {
    gif = _gif;
    layerIncrement = 0.01;
    maskIncrement = 0.0005;
    
    numLayers = 20;
    masker.setup(numLayers);
    
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 0.25, 1);

        img.setup("rust-tall2.png");
        img.setTextureScale(scale);
        img.setTextureOffset(i % 2 == 0 ? TEXTURE_OFFSET_TOP_LEFT : TEXTURE_OFFSET_TOP_RIGHT);
        img.setTextureOffsetY(ofRandom(2));
        layers.push_back(img);
        
        scale = ofMap(i, 0, numLayers-1, 0.5, 1.3);
        img.setup("circle-feather.png", scale, TEXTURE_OFFSET_MIDDLE_CENTER);
        img.setTextureOffsetY(ofRandom(2));
        masks.push_back(img);
    }
}

void Pattern2::update() {
    for(int i = 0; i < numLayers; i++) {
        masker.beginLayer(i);
        {
            gif->rotateAroundCenter(i * 90);
            ofSetColor(ofColor(ofColor::white, 160));
            increment = ofMap(i, 0, numLayers-1, layerIncrement, -layerIncrement);
            layers.at(i).incrementTextureScale(i % 2 == 0 ? increment : -increment * 8);
            layers.at(i).incrementTextureOffsetX((i % 2 == 0 ? increment : -increment) * ofRandom(-2, 27));
            layers.at(i).incrementTextureOffsetY((i % 2 == 0 ? -increment : increment) * ofRandom(-2, 27));
            layers.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            ofSetColor(ofColor::white);
            ofBackground(ofColor::white);
            increment = ofMap(i, 0, numLayers-1, maskIncrement, -maskIncrement);
            masks.at(i).incrementTextureOffsetY(increment);
            i % 2 == 0 ? masks.at(i).draw() : masker.drawLayer(i - 1, false);
        }
        masker.endMask(i);
    }
}

void Pattern2::draw() {
    masker.drawLayer(4);
    masker.drawLayer(9);
    masker.drawLayer(12);
    masker.drawLayer(13);
    masker.drawLayer(16);
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