#include "LensFlareCentralGlow.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralGlow::LensFlareCentralGlow()
{
    Surface img = loadImage( loadResource( "centre-1.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralGlow::draw( LensFlare * flare )
{
    float scaled = 1024 * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
    gl::rotate( flare->getAngle() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

