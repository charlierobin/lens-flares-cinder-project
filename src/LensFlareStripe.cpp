#include "LensFlareStripe.hpp"

using namespace ci;
using namespace ci::app;

LensFlareStripe::LensFlareStripe()
{
    Surface img = loadImage( loadResource( "stripes.jpg" ) );
    texture_ = gl::Texture::create( img );
}

void LensFlareStripe::draw( LensFlare * flare )
{
    float scaled = scale_ * 1024 * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
//    gl::translate( - scaled / 2, - scaled / 2 );
    
    gl::rotate( flare->getAngle() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
    
}


