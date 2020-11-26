#include "LensFlarePolygon.hpp"

using namespace ci;
using namespace ci::app;

LensFlarePolygon::LensFlarePolygon()
{
    Surface img = loadImage( loadResource( "pentagon.jpg" ) );
    
    texture_ = gl::Texture::create( img );
    
    positionOnAxis_ = randFloat( 0.1, 1.0 );
    
    scale_ = randFloat( 0.1, 0.3 );
}

void LensFlarePolygon::draw( LensFlare * flare )
{
    float scaled = 512 * scale_ * flare->getComputedIntensity();
    
    vec2 position = flare->getPositionOnAxis( positionOnAxis_ );
    
    gl::ScopedModelMatrix scope;
    
    gl::ScopedColor color( 0.75, 0.75, 0.75, 0.2 );

    gl::translate( position );
    
    gl::rotate( flare->getAngle() );

    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}
