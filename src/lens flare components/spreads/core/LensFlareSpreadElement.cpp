#include "LensFlareSpreadElement.hpp"

using namespace ci;
using namespace ci::app;

LensFlareSpreadElement::LensFlareSpreadElement( std::string resourceName )
{
    // 1 is at exact opposite of axis, 0 is on the light point, 0.5 centre between light and opposite end of axis, ie: axis point
    
    positionOnAxis_ = randFloat( 0.1, 2 );
    
//    positionOnAxis_ = 0.5;
    
    scale_ = randFloat( 0.1, 0.3 );
    
    Surface img = loadImage( loadResource( resourceName ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareSpreadElement::draw( LensFlareSpread * spread, LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    vec2 position = flare->getPositionOnAxis( positionOnAxis_ );
    
    gl::ScopedModelMatrix scope;
    
    gl::ScopedColor color( 0.75, 0.75, 0.75, 0.2 );
    
    gl::translate( position );
    
    gl::rotate( flare->getAngle() );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

