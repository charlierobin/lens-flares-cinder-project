#include "LensFlareCentralRingFadingInner.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralRingFadingInner::LensFlareCentralRingFadingInner()
{
    Surface img = loadImage( loadResource( "fading-ring-inner.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralRingFadingInner::draw( LensFlare * flare )
{
    float scaled = scale_ * texture_->getWidth() * flare->getComputedIntensity();
    
    gl::translate( flare->position_ );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

