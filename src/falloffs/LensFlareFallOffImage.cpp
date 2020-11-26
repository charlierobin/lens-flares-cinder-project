#include "LensFlareFallOffImage.hpp"

using namespace ci;
using namespace ci::app;

LensFlareFallOffImage::LensFlareFallOffImage()
{
    radius_ = 5;
}

LensFlareFallOffImage::LensFlareFallOffImage( std::string resourceName )
{
    radius_ = 5;
    
    setImage( resourceName );
}

float LensFlareFallOffImage::calculate( vec2 position )
{
    if ( radius_ == 0 )
    {
        auto sample = surface_.getPixel( position );
    
        return sample.r / 255.0;
    }
    
    Area area = Area ( vec2( position.x - radius_, position.y - radius_ ), vec2( position.x + radius_, position.y + radius_ ) );
    
    float total = 0;
    
    Surface::Iter iter = surface_.getIter( area );
    
    while ( iter.line() ) {
        
        while ( iter.pixel() ) {
            
            total = total + iter.r();
        }
    }
    
    return total / ( ( radius_ * 2 ) * ( radius_ * 2 ) * 255 );
}

void LensFlareFallOffImage::setImage( Surface surface )
{
    if ( surface.getWidth() != getWindowWidth() || surface.getHeight() != getWindowHeight() )
    {
        Surface surfaceResized = Surface8u( getWindowWidth(), getWindowHeight(), false );
        
        ip::resize( surface, &surfaceResized );
        
        surface_ = surfaceResized;
    }
    else
    {
        surface_ = surface;
    }
}

void LensFlareFallOffImage::setImage( std::string resourceName )
{
    Surface surface = loadImage( loadResource( resourceName ) );
    
    setImage( surface );
}

void LensFlareFallOffImage::drawDebug()
{
    gl::Texture2dRef texture = gl::Texture::create( surface_ );

    gl::draw( texture );
}

void LensFlareFallOffImage::windowResized()
{
    Surface surfaceResized = Surface8u( getWindowWidth(), getWindowHeight(), false );
    
    ip::resize( surface_, &surfaceResized );
    
    surface_ = surfaceResized;
}

// TODO this all needs a bit of thinking about ...
