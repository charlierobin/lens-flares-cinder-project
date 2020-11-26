#include "LensFlarePolygonSpread.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

LensFlarePolygonSpread::LensFlarePolygonSpread( int numberOfPolygons )
{
    for ( int i = 0; i < numberOfPolygons; ++i )
    {
        polygons_.push_back( new LensFlarePolygon() );
    }
}

void LensFlarePolygonSpread::draw( LensFlare * flare )
{
    for ( auto polygon : polygons_ )
    {
        polygon->draw( flare );
    }
}

