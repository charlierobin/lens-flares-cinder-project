#include "LensFlarePollux.hpp"

using namespace ci;
using namespace ci::app;

LensFlarePollux::LensFlarePollux()
{
    texture_ = gl::Texture::create( loadImage( loadResource( "pollux-raw.jpg" ) ) );
    
    textureFG_ = gl::Texture::create( loadImage( loadResource( "pollux-mono-fg.jpg" ) ) );
    textureBG_ = gl::Texture::create( loadImage( loadResource( "pollux-mono-bg.jpg" ) ) );
}

void LensFlarePollux::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    gl::translate( flare->position_ );
    
    gl::rotate( flare->angle_ );
    
    gl::ScopedColor color( flare->colour_ );
    
    gl::draw( textureBG_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
    
    gl::ScopedColor color2( 1, 1, 1 );
    
    gl::draw( textureFG_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
    
}


