#include "LensFlareCentralPolySpike.hpp"

using namespace ci;
using namespace ci::app;

LensFlareCentralPolySpike::LensFlareCentralPolySpike()
{
    Surface img = loadImage( loadResource( "polyspike.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareCentralPolySpike::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    gl::translate( flare->getPosition() );
    
    gl::rotate( flare->getAngle() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

