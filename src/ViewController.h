//
//  ViewController.hpp
//  miniVenn
//
//  Created by Cameron Browning on 4/12/17.
//
//

#ifndef ViewController_hpp
#define ViewController_hpp

#include "poScene/ImageView.h"
#include "poScene/ViewController.h"

#include "Bubble.h"

#include <stdio.h>

using namespace ci;
using namespace std;


class miniVennApp;

namespace minivenn{
    
    class ViewController;
    typedef std::shared_ptr<minivenn::ViewController> ViewControllerRef;
    


    class ViewController : public po::scene::ViewController{
        
    public:
        ViewController();
        static ViewControllerRef create();
        void setup();
        void update();
        void centerABubble();
        void sideBubbles();
        
        void fadeTheBigs();
        
        void keyPressed(ci::app::KeyEvent &key);
        
    protected:
        
    private:
        void reset();
        vector<BubbleRef> bubbles;
        
        gl::Texture2dRef mTex;
        po::scene::ImageViewRef img;
        
        int numBubbles;
        
        
    };
    
}

#endif /* ViewController_hpp */
