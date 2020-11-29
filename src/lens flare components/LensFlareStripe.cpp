#include "LensFlareStripe.hpp"

using namespace ci;
using namespace ci::app;

LensFlareStripe::LensFlareStripe()
{
    Surface img = loadImage( loadResource( "stripes.jpg" ) );
    texture_ = gl::Texture::create( img );
}

void LensFlareStripe::draw( LensFlare * flare )
{
    float scaled = scale_ * texture_->getWidth() * flare->getComputedIntensity();
    
    gl::translate( flare->position_ );
        
    gl::rotate( flare->angle_ );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
    
}


