#include "LensFlareApertureReflection.hpp"

using namespace ci;
using namespace ci::app;

LensFlareApertureReflection::LensFlareApertureReflection()
{
    Surface img = loadImage( loadResource( "aperture-flare.jpg" ) );
    texture_ = gl::Texture::create( img );
}

void LensFlareApertureReflection::draw( LensFlare * flare )
{
    float scaled = texture_->getWidth() * scale_ * flare->getIntensity();
    
    float x = flare->getPosition().x;
    float y = flare->getPosition().y;
    
    if ( x >= 0 && x <= getWindowWidth() && y >= 0 && y <= getWindowHeight() ) return;
    if ( x <  -100 || x > getWindowWidth() + 100 || y <  -100 || y > getWindowHeight() + 100 ) return;
    
    gl::ScopedModelMatrix scope;
    
    if ( x < 0 && x >= -100 )
    {
        gl::translate( 0, y );
        
        scaled = scaled * calculateScale( x );
    }
    else if ( x > getWindowWidth() && x <= getWindowWidth() + 100 )
    {
        gl::translate( getWindowWidth(), y );
        gl::rotate( 3.14 );
        
        scaled = scaled * calculateScale( x - getWindowWidth() );
    }
    else if ( y < 0 && y >= -100 )
    {
        gl::translate( x, 0 );
        gl::rotate( 3.14 / 2 );
        
        scaled = scaled * calculateScale( y );
    }
    else if ( y > getWindowHeight() && y <= getWindowHeight() + 100 )
    {
        gl::translate( x, getWindowHeight() );
        gl::rotate( ( 3.14 * 2 ) * 0.75 );
        
        scaled = scaled * calculateScale( y - getWindowHeight() );
    }
    
    gl::draw( texture_, Rectf( 0, - scaled / 2, scaled, scaled / 2 ) );
}

float LensFlareApertureReflection::calculateScale( float value )
{
    value = std::abs( value );
    
    if ( value < 50 )
    {
        // scales down from 50 to 0
        return value / 50.0;
    }
    // scales down from 50 to 100
    return (  100.0 - value ) / 50.0;
}


