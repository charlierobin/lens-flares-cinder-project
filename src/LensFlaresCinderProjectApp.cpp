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
    void resize() override;

    void keyDown( KeyEvent event ) override;
    
private:
    
    CameraPersp camera_;
    gl::BatchRef sphere_;
    gl::BatchRef maskSphere_;
    
    gl::GlslProgRef stockColourOnlyShader_;
    
    gl::GlslProgRef stockLambertWithTextureShader_;
    gl::Texture2dRef texture_;
    
    bool showMask = false;
    
    LensFlare* flare;
};

#define CENTRE_OF_THE_WORLD cinder::vec3( 0, 0, 0 )
#define CAMERA_POSITION cinder::vec3( 0, 0, -100.0f )

void LensFlaresCinderProjectApp::setup()
{
    setFrameRate( 60.0f );
    
    camera_.lookAt( CAMERA_POSITION, CENTRE_OF_THE_WORLD );
    camera_.setFarClip( 20000.0f );
    
    stockLambertWithTextureShader_ = cinder::gl::context()->getStockShader( cinder::gl::ShaderDef().texture().lambert() );
    stockColourOnlyShader_ = cinder::gl::context()->getStockShader( cinder::gl::ShaderDef().color() );
    
    texture_ = gl::Texture::create( loadImage( loadResource( "earth-texture.jpg" ) ) );
    
    sphere_ = gl::Batch::create( geom::Sphere().subdivisions( 24 ).radius( 25 ), stockLambertWithTextureShader_ );
    
    maskSphere_ = gl::Batch::create( geom::Sphere().subdivisions( 24 ).radius( 25 ), stockColourOnlyShader_ );
    
    
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

void LensFlaresCinderProjectApp::keyDown( KeyEvent event )
{
    if ( event.getCode() == KeyEvent::KEY_SPACE ) showMask = ! showMask;
}

void LensFlaresCinderProjectApp::resize()
{
    camera_.setAspectRatio( getWindowAspectRatio() );
}

void LensFlaresCinderProjectApp::draw()
{
    // render mask
    
    gl::clear( Color( 0, 0, 0 ) );
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    gl::setMatrices( camera_ );
    
    gl::pushModelMatrix();
    
    maskSphere_->draw();
    
    // TODO !
    
    if ( showMask ) return;
    
    Surface mask = copyWindowSurface();
    
    
    flare->setMask( &mask );
    
    
    // render beauty pass
    
    gl::clear( Color( 0, 0, 0 ) );
    
    cinder::gl::ScopedTextureBind tex0( texture_ );
    
    sphere_->draw();
    
    gl::popModelMatrix();
    
    gl::setMatricesWindow( getWindowSize() );
    
    flare->draw();
}

CINDER_APP( LensFlaresCinderProjectApp, RendererGl )
