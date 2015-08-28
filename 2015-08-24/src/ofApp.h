#pragma once

#include "ofMain.h"
#include "ofxGifEncoderTemplate.h"
#include "ofxTexturePlane.h"
#include "ofxLayerMask.h"

class MaskArray {
    
public:
    void setup(int _number, float _size);
    void draw();
protected:
    void bounce(int i);
    void debug();
    int number;
    float size, unitSize;
    vector<float> alphas, speeds;
    vector<int> directions;
};

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxGifEncoderTemplate gif;
    ofxLayerMask masker;
    ofxTexturePlane img1, img2;
    int numLayers;
    MaskArray horizontalMasks;
};