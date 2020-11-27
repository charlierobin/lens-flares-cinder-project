#include "LensFlareCentralRing.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralRing::LensFlareCentralRing()
{
    Surface img = loadImage( loadResource( "ring.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralRing::draw( LensFlare * flare )
{
    float scaled = scale_ * texture_->getWidth() * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}


