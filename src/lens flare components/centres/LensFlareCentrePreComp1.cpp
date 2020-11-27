#include "LensFlareCentrePreComp1.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentrePreComp1::LensFlareCentrePreComp1()
{
    Surface img = loadImage( loadResource( "centre-1.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentrePreComp1::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
    gl::rotate( flare->getAngle() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

