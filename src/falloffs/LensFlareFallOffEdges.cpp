#include "LensFlareFallOffEdges.hpp"

using namespace ci;
using namespace ci::app;

LensFlareFallOffEdges::LensFlareFallOffEdges()
{
    margin_ = 5;
}

float LensFlareFallOffEdges::calculate( vec2 position )
{
    if ( position.x < 0 ) return 0;
    
    if ( position.x < margin_ )
    {
        return position.x / margin_;
    }
    
    
    if ( position.y < 0 ) return 0;
    
    if ( position.y < margin_ )
    {
        return position.y / margin_;
    }
    
    
    if ( position.x > getWindowSize().x ) return 0;
    
    if ( position.x > getWindowSize().x - margin_ )
    {
        return ( getWindowSize().x - position.x ) / margin_;
    }
    
    
    if ( position.y > getWindowSize().y ) return 0;
    
    if ( position.y > getWindowSize().y - margin_ )
    {
        return ( getWindowSize().y - position.y ) / margin_;
    }
    
    
    return 1;
}



// TODO

// falloffs: from a point, above/below a horiz, left/right a vertical, a rect, a circle, texture ... ?

