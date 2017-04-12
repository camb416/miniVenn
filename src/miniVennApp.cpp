#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class miniVennApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void miniVennApp::setup()
{
}

void miniVennApp::mouseDown( MouseEvent event )
{
}

void miniVennApp::update()
{
}

void miniVennApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( miniVennApp, RendererGl )
