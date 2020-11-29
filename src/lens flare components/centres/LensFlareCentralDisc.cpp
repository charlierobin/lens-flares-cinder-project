#include "LensFlareCentralDisc.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralDisc::LensFlareCentralDisc()
{
    Surface img = loadImage( loadResource( "disc.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralDisc::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    gl::translate( flare->position_ );
    
    gl::rotate( flare->angle_ );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

