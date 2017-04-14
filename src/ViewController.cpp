//
//  ViewController.cpp
//  miniVenn
//
//  Created by Cameron Browning on 4/12/17.
//
//

#include "ViewController.h"

#include "cinder/Log.h"
#include "cinder/Rand.h"

using namespace ci;

namespace minivenn{
    
    ViewController::ViewController(){
        // empty constructor
    }
    ViewControllerRef ViewController::create(){
        ViewControllerRef node (new ViewController());
        node->setup();
        return node;
    }
    
    void ViewController::reset(){
        
        for(int i=0;i<numBubbles;i++){
            BubbleRef b = bubbles.at(i);
            getView()->removeSubview(b);
        }
        
        bubbles.clear();
        
        for(int i=0;i<numBubbles;i++){
            BubbleRef b = Bubble::create();
            bubbles.push_back(b);
            getView()->addSubview(b);
        }
        
    }
    
    void ViewController::setup(){

        mTex = gl::Texture2d::create(loadImage(cinder::app::loadAsset("heart_stats.png")));
        
        img = po::scene::ImageView::create(mTex);
        
        //img->setScale(1440.0f/2835.0f);
        img->setScale(1440.0f/1712.0f);
        getView()->addSubview(img);
        
        
        
         ci::app::getWindow()->getSignalKeyDown().connect(std::bind(&ViewController::keyPressed, this, std::placeholders::_1));
        
        numBubbles = 512;
        
        for(int i=0;i<numBubbles;i++){
            BubbleRef b = Bubble::create();
            bubbles.push_back(b);
            getView()->addSubview(b);
        }

    }
    void ViewController::update(){
        
    }
    void ViewController::centerABubble(){
        int randomBubble = randFloat()*numBubbles;
        bubbles.at(randomBubble)->toCenter();
        CI_LOG_V(randomBubble);
    }
    void ViewController::sideBubbles(){
        int numBubblesToMove = 5;
        
        float leftX = app::getWindowWidth()*2.0f/3.0f/4.0f;
        float rightX = app::getWindowWidth()*2.0f/3.0f/4.0f*3.0f;
        float leftSize = 70.0f;
        float rightSize = 45.0f;
        
        
        
        for(int i=0;i<numBubbles;i++){
            BubbleRef b = bubbles.at(i);
            if(b->getAnimState() == 1){
                float whereTo = leftX;
                float whatSize = leftSize;
                if(numBubblesToMove%2==0){
                    whereTo = rightX;
                    whatSize = rightSize;
                }
                b->toSides(whereTo,whatSize);
                numBubblesToMove--;
                if(numBubblesToMove == 0){
                    break;
                }
            }
        }
    }
    
    void ViewController::fadeTheBigs(){
        for(int i=0;i<numBubbles;i++){
            BubbleRef b = bubbles.at(i);
            if(b->getAnimState() > 0 ){
                b->fadeOut();
            } else {
                b->fadeOut(1.5f); // fade out, but wait 3s to do so.
            }
        }
    }
    
    void ViewController::keyPressed(ci::app::KeyEvent &key){
        switch(key.getChar()){
                
                case 'f':
                case 'F':
                fadeTheBigs();
                break;
                case 'r':
                case 'R':
                reset();
                break;
                case 's':
                case 'S':
                sideBubbles();
                break;
            default:
                centerABubble();
                break;
        }
    

    }
    
    
    
}
