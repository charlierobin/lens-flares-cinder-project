#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "LensFlare.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class LensFlaresCinderProjectApp : public App {
    
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void mouseDrag( MouseEvent event ) override;
    void draw() override;
    
private:
    LensFlare* flare;
};

void LensFlaresCinderProjectApp::setup()
{
    flare = new LensFlare();
}

void LensFlaresCinderProjectApp::mouseDown( MouseEvent event )
{
    flare->setPosition( event.getPos() );
}

void LensFlaresCinderProjectApp::mouseDrag( MouseEvent event )
{
    flare->setPosition( event.getPos() );
}

void LensFlaresCinderProjectApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    
    flare->draw();
}

CINDER_APP( LensFlaresCinderProjectApp, RendererGl )
