#pragma once

#include "ofMain.h"
#include "ofxGifEncoderTemplate.h"
#include "ofxLayerMask.h"
#include "ofxTexturePlane.h"

class Pattern1 {
public:
    void setup(ofxGifEncoderTemplate *_gif);
    void update();
    void draw();
    ofxGifEncoderTemplate *gif;
    ofxLayerMask masker;
    ofxTexturePlane img;
    vector<ofxTexturePlane> textures, masks;
    int numLayers, numRects;
    float scale, rectWidth;
    vector<float> rectAlphaMultipliers;
};

class Pattern2 {
public:
    void setup(ofxGifEncoderTemplate *_gif);
    void update();
    void draw();
    ofxGifEncoderTemplate *gif;
    ofxLayerMask masker;
    ofxTexturePlane img;
    vector<ofxTexturePlane> textures, masks;
    int numLayers, numRects;
    float scale, rectWidth;
    vector<float> rectAlphaMultipliers;
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

    Pattern1 pattern1;
    Pattern2 pattern2;
    ofxLayerMask masker;
    ofxGifEncoderTemplate gif;
};
