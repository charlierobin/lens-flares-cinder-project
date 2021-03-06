#include "LensFlareCentralGlow.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralGlow::LensFlareCentralGlow()
{
    Surface img = loadImage( loadResource( "glow.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralGlow::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    gl::translate( flare->position_ );
    
    gl::rotate( flare->angle_ );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

