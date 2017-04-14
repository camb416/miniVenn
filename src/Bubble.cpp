//
//  Bubble.cpp
//  miniVenn
//
//  Created by Cameron Browning on 4/12/17.
//
//

#include "cinder/Rand.h"

#include "Bubble.h"

using namespace ci;

namespace minivenn{
    
    
    
    BubbleRef Bubble::create(){
        BubbleRef node ( new Bubble());
        node->setup();
        return node;
    }
    
    Bubble::Bubble(){
        // empty constructor
    }
    
    void Bubble::setup(){
        waveSpeed = 1.0f;
                radius = randFloat()*8.0f;
        
        animState = 0;
        color = ColorA(1,1,1,0);

        seed = randFloat()*M_PI;
        
        float c = radius/8.0f;
        oRadius = radius;
        ci::app::timeline().appendTo( &color, ColorA(1,1,1,c), seed, ci::EaseInOutCubic());
        

        pos = oPos = vec2(randFloat()*(app::getWindowWidth()+100)-50, randFloat()*50-25+app::getWindowHeight());
        
    }
    void Bubble::update(){
        
        if(animState == 3){
            waveSpeed +=0.3f;
        }
        
        if(animState == 0 || animState == 3){
            
     
        pos = pos.value() + vec2(2.0f,sin(app::getElapsedSeconds()*(2.0f+seed)+ seed)/3.0f)*1.0f;
            
        if(pos.value().x > app::getWindowWidth() + 50){
            pos.value().x = -1.0f*(pos.value().x - app::getWindowWidth());
        }
               }
    }
    void Bubble::draw(){
        gl::color(color);
        gl::drawSolidCircle(pos,radius);
    }
    
    void Bubble::fadeOut(float _delay){
        if(animState == 0) animState = 3;
        ColorA c = ColorA(1.0f,1.0f,1.0f,0.0f);
        
        app::timeline().apply(&color,
                              c,
                              randFloat()*2.0f + 1.0f,
                              EaseInOutCubic()).delay(_delay);
    
        app::timeline().apply(&radius,
                              oRadius,
                              randFloat() * 2.0f,
                              EaseInOutCubic());
        
        
    }
    
    void Bubble::toSides(float _destinationX, float _scale){
        animState = 2;
        vec2 dest = vec2(_destinationX, app::getWindowCenter().y);
        radius = oRadius;
        app::timeline().appendTo(&pos,
                                dest,
                                1.0f+seed/8.0f,
                                EaseInOutCubic());
        app::timeline().apply(&radius,
                                 _scale,
                                 1.5f+seed/4.0f,
                                 EaseInOutCubic());
    
    }
    
    void Bubble::toCenter(){
       animState = 1;
        
        vec2 destPos = vec2(app::getWindowWidth()*2.0f/3.0f/2.0f, app::getWindowHeight()/2.0f);
        
        float destinationSize = 125.0f;
        
        app::timeline().appendTo(&pos,
                                 destPos,
                                 1.0f+radius/4.0f,
                                 ci::EaseInOutCubic());
        app::timeline().appendTo(&radius,
                                 destinationSize,
                                 1.0f/(radius+1.0f)+ 3.0f,
                                 ci::EaseInOutCubic()).delay(1.0f);
        app::timeline().appendTo(&color,
                                 ColorA(1.0f,1.0f,1.0f, 1.0f),
                                 1.0f,
                                 ci::EaseInOutCubic());

    }
    
    void Bubble::split(float _destX){
        
    }
    
    
}
