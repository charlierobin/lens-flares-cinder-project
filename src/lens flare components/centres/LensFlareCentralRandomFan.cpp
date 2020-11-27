#include "LensFlareCentralRandomFan.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralRandomFan::LensFlareCentralRandomFan()
{
    Surface img = loadImage( loadResource( "random-fan.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralRandomFan::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
    gl::rotate( flare->getAngle() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

