#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "poScene/Scene.h"

#include "ViewController.h"
#include "Bubble.h"

using namespace po::scene;

using namespace ci;
using namespace ci::app;
using namespace std;

class miniVennApp : public App {
  public:
	void setup() override;
    void mouseDown( po::scene::MouseEvent event );
    
	void update() override;
	void draw() override;
    
    SceneRef mScene;
    
    ViewControllerRef mViewController;
    
    
};

void miniVennApp::setup()
{
    mViewController = minivenn::ViewController::create();
    mScene = Scene::create(mViewController);
    
}

void miniVennApp::mouseDown( po::scene::MouseEvent event )
{
   }

void miniVennApp::update()
{
    
    mScene->update();
}

void miniVennApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    mScene->draw();
}
void prepareSettings(miniVennApp::Settings * settings){
    settings->setHighDensityDisplayEnabled();
    settings->setMultiTouchEnabled(false);
    settings->setWindowSize(1440,215);
}

CINDER_APP( miniVennApp, RendererGl(RendererGl::Options().msaa(4)), prepareSettings )
