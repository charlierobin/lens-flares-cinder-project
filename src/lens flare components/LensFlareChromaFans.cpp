#include "LensFlareChromaFans.hpp"

using namespace ci;
using namespace ci::app;

LensFlareChromaFans::LensFlareChromaFans()
{
    Surface img = loadImage( loadResource( "fan.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareChromaFans::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    float radius = flare->getComputedIntensity() * 300;
    
    gl::ScopedColor color( 1, 1, 1, 1 );
    
    {
        gl::ScopedModelMatrix scope;
        
        gl::translate( flare->getPosition() );
        
        gl::rotate( angle_ );
        
        gl::translate( 0, radius );
        
        
        gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
    }
    
    {
        gl::ScopedModelMatrix scope;
        
        gl::translate( flare->getPosition() );
        
        gl::rotate( angle_ );
        
        gl::translate( 0, - radius );
        
        
        gl::rotate( 3.14 );
        
        
        gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
    }
}

