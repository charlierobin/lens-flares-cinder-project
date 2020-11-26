#include "LensFlareFallOffPoint.hpp"

using namespace ci;
using namespace ci::app;

LensFlareFallOffPoint::LensFlareFallOffPoint()
{
    point_ = vec2( 100, 100 );
    
    maxDistance_ = 200;
}

float LensFlareFallOffPoint::calculate( vec2 position )
{
    float distance = sqrt( pow ( point_.x - position.x, 2 ) + pow ( point_.y - position.y, 2 ) );
    
    return fmin( distance / maxDistance_, 1 );
}

