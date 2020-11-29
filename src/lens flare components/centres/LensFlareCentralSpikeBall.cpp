#include "LensFlareCentralSpikeBall.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralSpikeBall::LensFlareCentralSpikeBall()
{
    Surface img = loadImage( loadResource( "spike-ball.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralSpikeBall::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    gl::translate( flare->position_ );
    
    gl::rotate( flare->angle_ );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

