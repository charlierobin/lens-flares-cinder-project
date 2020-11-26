#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "cinder/CinderImGui.h"

#include "CustomLensFlare.hpp"

#include "LensFlareFallOffPoint.hpp"
#include "LensFlareFallOffImage.hpp"
#include "LensFlareFallOffCircle.hpp"
#include "LensFlareFallOffEdges.hpp"

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
    
    bool showMask_ = false;
    
    int clickSetsLight_ = 1;
    
    LensFlare* flare;
    
    float intensity_;
    float angle_;
    
    bool altWasDownWhenMouseFirstClicked_;
    
};

#define CENTRE_OF_THE_WORLD cinder::vec3( 0, 0, 0 )
#define CAMERA_POSITION cinder::vec3( 0, 0, -100 )

void LensFlaresCinderProjectApp::setup()
{
    ImGui::Initialize();
    
    setFrameRate( 60 );
    
    camera_.lookAt( CAMERA_POSITION, CENTRE_OF_THE_WORLD );
    camera_.setFarClip( 20000 );
    
    stockLambertWithTextureShader_ = cinder::gl::context()->getStockShader( cinder::gl::ShaderDef().texture().lambert() );
    stockColourOnlyShader_ = cinder::gl::context()->getStockShader( cinder::gl::ShaderDef().color() );
    
    texture_ = gl::Texture::create( loadImage( loadResource( "earth-texture.jpg" ) ) );
    
    const float radius = 20;
    
    sphere_ = gl::Batch::create( geom::Sphere().subdivisions( 24 ).radius( radius ), stockLambertWithTextureShader_ );
    
    maskSphere_ = gl::Batch::create( geom::Sphere().subdivisions( 24 ).radius( radius ), stockColourOnlyShader_ );
    
    
    flare = new CustomLensFlare();
    
    flare->setPosition( vec2( getWindowWidth() / 2, getWindowHeight() / 2 ) );
    
    intensity_ = flare->getIntensity();
    
    angle_ = flare->getAngle();
    
    
//    flare->addFallOff( new LensFlareFallOffPoint() );
    
//    flare->addFallOff( new LensFlareFallOffCircle() );

//    flare->addFallOff( new LensFlareFallOffEdges() );
    
    flare->addFallOff( new LensFlareFallOffImage( "black-and-white-diagonal.jpg" ) );
}

void LensFlaresCinderProjectApp::mouseDown( MouseEvent event )
{
    altWasDownWhenMouseFirstClicked_ = event.isAltDown();
    
    if ( clickSetsLight_ )
    {
        if ( altWasDownWhenMouseFirstClicked_ )
        {
            flare->setAxis( event.getPos() );
        }
        else
        {
            flare->setPosition( event.getPos() );
        }
    }
    else
    {
        if ( altWasDownWhenMouseFirstClicked_ )
        {
            flare->setPosition( event.getPos() );
        }
        else
        {
            flare->setAxis( event.getPos() );
        }
    }
}

void LensFlaresCinderProjectApp::mouseDrag( MouseEvent event )
{
    if ( clickSetsLight_ )
    {
        if ( altWasDownWhenMouseFirstClicked_ )
        {
            flare->setAxis( event.getPos() );
        }
        else
        {
            flare->setPosition( event.getPos() );
        }
    }
    else
    {
        if ( altWasDownWhenMouseFirstClicked_ )
        {
            flare->setPosition( event.getPos() );
        }
        else
        {
            flare->setAxis( event.getPos() );
        }
    }
}

void LensFlaresCinderProjectApp::keyDown( KeyEvent event )
{
    if ( event.getCode() == KeyEvent::KEY_SPACE ) showMask_ = ! showMask_;
}

void LensFlaresCinderProjectApp::resize()
{
    flare->windowResized();
    
    camera_.setAspectRatio( getWindowAspectRatio() );
}

void LensFlaresCinderProjectApp::draw()
{
    ImGui::RadioButton( "Click sets light", &clickSetsLight_, 1 );
    ImGui::RadioButton( "Click sets axis", &clickSetsLight_, 0 );
    
    ImGui::Checkbox( "Show mask", &showMask_ );
    
    ImGui::Separator();
    
    ImGui::SliderFloat( "Intensity", &intensity_, 0.0, 5.0 );
    ImGui::SliderAngle( "Angle", &angle_ );
    
    // render mask
    
    gl::clear( Color( 0, 0, 0 ) );
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    gl::setMatrices( camera_ );
    
    gl::pushModelMatrix();
    
    maskSphere_->draw();
    
    // TODO
    
//    if ( showMask_ ) return;
    
//    Surface mask = copyWindowSurface();
    
    
//    flare->setMask( &mask );
    
    
    // render beauty pass
    
    gl::clear( Color( 0, 0, 0 ) );
    
    gl::ScopedTextureBind tex0( texture_ );
    
    sphere_->draw();
    
    gl::popModelMatrix();
    
    gl::setMatricesWindow( getWindowSize() );
    
    flare->setIntensity( intensity_ );
    flare->setAngle( angle_ );
    
    if ( showMask_ )
    {
        flare->drawDebug();
    }
    else
    {
        flare->draw();
    }
}

CINDER_APP( LensFlaresCinderProjectApp, RendererGl )



