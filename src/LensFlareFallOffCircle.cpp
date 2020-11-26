#include "LensFlareFallOffCircle.hpp"

using namespace ci;
using namespace ci::app;

LensFlareFallOffCircle::LensFlareFallOffCircle()
{
    centre_ = vec2( 100, 100 );
    
    radius_ = 100;
}

float LensFlareFallOffCircle::calculate( vec2 position )
{
    float distance = sqrt( pow ( centre_.x - position.x, 2 ) + pow ( centre_.y - position.y, 2 ) );
    
    if ( distance > radius_ )
    {
        return 1;
    }
    
    return 0;
}

