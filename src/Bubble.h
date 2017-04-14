//
//  Bubble.hpp
//  miniVenn
//
//  Created by Cameron Browning on 4/12/17.
//
//

#ifndef Bubble_hpp
#define Bubble_hpp

#include "poScene/View.h"

#include <stdio.h>

using namespace std;
using namespace ci;
using namespace po::scene;


namespace minivenn {
    class Bubble;
    typedef shared_ptr<Bubble> BubbleRef;
    
    class Bubble: public po::scene::View {
        
    public:
        
        Bubble();
        static BubbleRef create();
        void setup();
        void update();
        void draw();
        void toCenter();
        void split(float _destX);
        void toSides(float _destinationX, float _destinationRad);
        int getAnimState(){ return animState;};
        void fadeOut(float _delay = 0.0f);
        
    private:
        Anim<ColorA> color;
        Anim<vec2> pos;
        Anim<float> radius;
        float oRadius;
        
        float waveSpeed;
        
        vec2 oPos;

        float seed;
        
        int animState;
        
        void split();
        
    };
}

#endif /* Bubble_hpp */
