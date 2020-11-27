#include "LensFlareSpread.hpp"

#include "LensFlareSpreadElement.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

LensFlareSpread::LensFlareSpread( int numberOfElements, std::string resourceName )
{
    for ( int i = 0; i < numberOfElements; ++i )
    {
        elements_.push_back( new LensFlareSpreadElement( resourceName ) );
    }
}

void LensFlareSpread::draw( LensFlare * flare )
{
    for ( auto element : elements_ )
    {
        element->draw( this, flare );
    }
}

