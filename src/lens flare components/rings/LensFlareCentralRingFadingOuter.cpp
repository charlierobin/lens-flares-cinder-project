#include "LensFlareCentralRingFadingOuter.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralRingFadingOuter::LensFlareCentralRingFadingOuter()
{
    Surface img = loadImage( loadResource( "fading-ring-outer.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralRingFadingOuter::draw( LensFlare * flare )
{
    float scaled = scale_ * texture_->getWidth() * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}


