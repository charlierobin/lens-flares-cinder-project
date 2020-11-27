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
    float scaled = size_ * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}



