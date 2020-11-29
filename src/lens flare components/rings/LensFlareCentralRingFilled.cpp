#include "LensFlareCentralRingFilled.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralRingFilled::LensFlareCentralRingFilled()
{
    Surface img = loadImage( loadResource( "filled-ring.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralRingFilled::draw( LensFlare * flare )
{
    float scaled = scale_ * texture_->getWidth() * flare->getComputedIntensity();
    
    gl::translate( flare->position_ );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

