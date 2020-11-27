#include "LensFlareSunDogs.hpp"

using namespace ci;
using namespace ci::app;

LensFlareSunDogs::LensFlareSunDogs()
{
    Surface img = loadImage( loadResource( "filled-ring.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareSunDogs::draw( LensFlare * flare )
{
    float scaled = size_ * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}




// ring, two bits on each side, central pillar, etc ? cross?



