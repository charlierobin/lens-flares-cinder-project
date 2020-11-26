#include "LensFlareFallOffImagePointer.hpp"

using namespace ci;
using namespace ci::app;

LensFlareFallOffImagePointer::LensFlareFallOffImagePointer()
{
    radius_ = 2;
}

float LensFlareFallOffImagePointer::calculate( vec2 position )
{
    if ( radius_ == 0 )
    {
        auto sample = surface_->getPixel( position );
        
        return sample.r / 255.0;
    }
    
    Area area = Area ( vec2( position.x - radius_, position.y - radius_ ), vec2( position.x + radius_, position.y + radius_ ) );
    
    float total = 0;
    
    Surface::Iter iter = surface_->getIter( area );
    
    while ( iter.line() ) {
        
        while ( iter.pixel() ) {
            
            total = total + iter.r();
        }
    }
    
    return total / ( ( radius_ * 2 ) * ( radius_ * 2 ) * 255 );
}

void LensFlareFallOffImagePointer::set( Surface * surface )
{
    surface_ = surface;
}

void LensFlareFallOffImagePointer::drawDebug()
{
    gl::Texture2dRef texture = gl::Texture::create( *surface_ );
    
    gl::draw( texture );
}

// TODO this all needs a bit of thinking about ...

