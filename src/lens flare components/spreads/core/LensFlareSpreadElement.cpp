#include "LensFlareSpreadElement.hpp"

using namespace ci;
using namespace ci::app;

LensFlareSpreadElement::LensFlareSpreadElement( std::string resourceName )
{
    // 1 is at exact opposite of axis, 0 is on the light point, 0.5 centre between light and opposite end of axis, ie: axis point, lens "centre"
    
    positionOnAxis_ = randFloat( 0.1, 2 );
    
    //    positionOnAxis_ = 0.5;
    
    scale_ = randFloat( 0.1, 0.3 );
    
    alpha_ = randFloat( 0.1, 0.3 );
    
    Surface img = loadImage( loadResource( resourceName ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlareSpreadElement::generateColourVariation( float range )
{
    float variation = randFloat( -range, range );
    
    colourVariation_ = variation;
}

void LensFlareSpreadElement::draw( LensFlareSpread * spread, LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    
    vec2 position = flare->getPositionOnAxis( positionOnAxis_ );
    
    gl::ScopedModelMatrix scope;
    
    gl::ScopedColor colourScope;
    
    Colorf colour;
    
    if ( spread->useColour_ )
    {
        colour = Colorf( spread->colour_.r, spread->colour_.g, spread->colour_.b );
    }
    else
    {
        colour = Colorf( flare->colour_.r, flare->colour_.g, flare->colour_.b );
    }
    
    vec3 hsv = colour.get( CM_HSV );
    
    hsv = vec3( hsv.x + colourVariation_, hsv.y, hsv.z );
    
    if ( hsv.x > 1 ) hsv.x = hsv.x - 1.0;
    
    if ( hsv.x < 0 ) hsv.x = hsv.x + 1.0;
    
    colour.set( CM_HSV, hsv );
    
    gl::color( colour.r, colour.g, colour.b, alpha_ );
    
    gl::translate( position );
    
    gl::rotate( flare->angle_ );
    
    gl::draw( texture_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
}

