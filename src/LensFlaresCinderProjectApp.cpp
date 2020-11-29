#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "cinder/CinderImGui.h"

#include "CustomLensFlare1.hpp"
#include "CustomLensFlare2.hpp"
#include "CustomLensFlare3.hpp"

#include "LensFlareFallOffPoint.hpp"
#include "LensFlareFallOffImage.hpp"
#include "LensFlareFallOffImagePointer.hpp"
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
    
    bool showDebug_ = false;
    bool stopRenderHere_ = false;
    
    int clickSetsLight_ = 1;
    
    LensFlare * flare_;
    
    std::vector<LensFlare *> flares_;
    std::vector<LensFlareFallOff *> falloffs_;
    
    LensFlareFallOffImagePointer * mask_;
    
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
    
    stockLambertWithTextureShader_ = cinder::gl::context()->getStockShader( gl::ShaderDef().texture().lambert() );
    stockColourOnlyShader_ = cinder::gl::context()->getStockShader( gl::ShaderDef().color() );
    
    texture_ = gl::Texture::create( loadImage( loadResource( "earth-texture.jpg" ) ) );
    
    const float radius = 20;
    
    sphere_ = gl::Batch::create( geom::Sphere().subdivisions( 24 ).radius( radius ), stockLambertWithTextureShader_ );
    
    maskSphere_ = gl::Batch::create( geom::Sphere().subdivisions( 24 ).radius( radius ), stockColourOnlyShader_ );
    
    
    flares_.push_back( new CustomLensFlare1() );
    flares_.push_back( new CustomLensFlare2() );
    flares_.push_back( new CustomLensFlare3() );
    
    flare_ = flares_[ 0 ];
    
    
    
    mask_ = new LensFlareFallOffImagePointer();
    
    for ( auto flare : flares_ )
    {
        //    flare->addFallOff( new LensFlareFallOffPoint() );
        //    flare->addFallOff( new LensFlareFallOffCircle() );
        //    flare->addFallOff( new LensFlareFallOffEdges() );
        //    flare->addFallOff( new LensFlareFallOffImage( "black-and-white-diagonal.jpg" ) );
        
        flare->addFallOff( mask_ );
    }
}

void LensFlaresCinderProjectApp::mouseDown( MouseEvent event )
{
    altWasDownWhenMouseFirstClicked_ = event.isAltDown();
    
    if ( clickSetsLight_ )
    {
        if ( altWasDownWhenMouseFirstClicked_ )
        {
            flare_->axis_ = event.getPos();
        }
        else
        {
            flare_->position_ = event.getPos();
        }
    }
    else
    {
        if ( altWasDownWhenMouseFirstClicked_ )
        {
            flare_->position_ = event.getPos();
        }
        else
        {
            flare_->axis_ = event.getPos();
        }
    }
}

void LensFlaresCinderProjectApp::mouseDrag( MouseEvent event )
{
    if ( clickSetsLight_ )
    {
        if ( altWasDownWhenMouseFirstClicked_ )
        {
            flare_->axis_ = event.getPos();
        }
        else
        {
            flare_->position_ = event.getPos();
        }
    }
    else
    {
        if ( altWasDownWhenMouseFirstClicked_ )
        {
            flare_->position_ = event.getPos();
        }
        else
        {
            flare_->axis_ = event.getPos();
        }
    }
}

void LensFlaresCinderProjectApp::keyDown( KeyEvent event )
{
    if ( event.getCode() == KeyEvent::KEY_SPACE ) showDebug_ = ! showDebug_;
}

void LensFlaresCinderProjectApp::resize()
{
    flare_->windowResized();
    
    camera_.setAspectRatio( getWindowAspectRatio() );
}

void LensFlaresCinderProjectApp::draw()
{
    ImGui::Begin( "Flare controls" );
    
    for ( auto flare : flares_ )
    {
        if ( ImGui::Button( flare->name_.c_str() ) )
        {
            flare_ = flare;
        }
        
        if ( flare == flare_ )
        {
            ImGui::SameLine();
            ImGui::Text( "<<<<<" );
        }
    }
    
    ImGui::RadioButton( "Click sets light", &clickSetsLight_, 1 );
    ImGui::RadioButton( "Click sets axis", &clickSetsLight_, 0 );
    
    ImGui::Text( "(Or hold down ALT when clicking & dragging)" );
    
    ImGui::Separator();
    
    ImGui::Checkbox( "Show debug", &showDebug_ );
    ImGui::Checkbox( "Render mask", &stopRenderHere_ );
    
    ImGui::Separator();
    
    ImGui::Checkbox( "Invert falloff", &flare_->invertFallOff_ );
    
    ImGui::SliderFloat( "Intensity", &flare_->intensity_, 0.0, 5.0 );
    ImGui::SliderAngle( "Angle", &flare_->angle_ );
    
    ImGui::ColorPicker3( "Colour", &flare_->colour_ );
    
    
    for ( auto element : flare_->getElements() )
    {
        element->ui();
    }
    
    ImGui::End();
    
    // render mask
    
    gl::clear( Color( 1, 1, 1 ) );
    
    gl::enableDepth();
    
    gl::setMatrices( camera_ );
    
    gl::pushModelMatrix();
    
    gl::color( 0, 0, 0 );
    
    maskSphere_->draw();
    
    
    if ( stopRenderHere_ ) return;
    
    
    Surface renderedMask = copyWindowSurface();
    
    mask_->set( & renderedMask );
    
    
    // render beauty pass
    
    gl::clear( Color( 0, 0, 0 ) );
    
    gl::ScopedTextureBind tex0( texture_ );
    
    sphere_->draw();
    
    gl::popModelMatrix();
    
    gl::setMatricesWindow( getWindowSize() );
    
    if ( showDebug_ )
    {
        flare_->drawDebug();
    }
    else
    {
        flare_->draw();
    }
}

CINDER_APP( LensFlaresCinderProjectApp, RendererGl )



