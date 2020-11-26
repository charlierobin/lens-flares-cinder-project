#include "LensFlareChromaHoop.hpp"

using namespace ci;
using namespace ci::app;

LensFlareChromaHoop::LensFlareChromaHoop()
{
    Surface img = loadImage( loadResource( "chroma-hoop.jpg" ) );
    texture_ = gl::Texture::create( img );
}

void LensFlareChromaHoop::draw( LensFlare * flare )
{
    // TODO
    
    if ( flare->getComputedIntensity() < 0.01 ) return;
    
    float scaledWidth = flare->getDistanceFromCentre() * 2;
    
    scaledWidth = scaledWidth - ( scaledWidth / 1024 );
    
    float scaledHeight = scaledWidth;
    
    float alpha = flare->scaleBetween( scaledWidth, 400, 200 );
    
    alpha = alpha / 2;
    
    if ( scaledWidth > getWindowWidth() + 500 ) return;
    
    gl::ScopedColor colour( 1, 1, 1, alpha );
    
    gl::ScopedModelMatrix scope;
    
    gl::translate( flare->getAxis() );
    
    gl::rotate( flare->getAngleFromCentre() );
    
    gl::draw( texture_, Rectf( - scaledWidth / 2, - scaledHeight / 2, scaledWidth / 2, scaledHeight / 2 ) );
}

