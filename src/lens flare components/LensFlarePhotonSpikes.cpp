#include "LensFlarePhotonSpikes.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

LensFlarePhotonSpikes::LensFlarePhotonSpikes( int numberOfSpikes )
{
    for ( int i = 0; i < numberOfSpikes; ++i )
    {
        spikes_.push_back( new LensFlarePhotonSpike() );
    }
}

void LensFlarePhotonSpikes::draw( LensFlare * flare )
{
    for ( auto spike : spikes_ )
    {
        spike->draw( flare );
    }
}


