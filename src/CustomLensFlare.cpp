#include "CustomLensFlare.hpp"

CustomLensFlare::CustomLensFlare()
{
    add( new LensFlareCentralGlow() );
    add( new LensFlarePolygonSpread( 5 ) );
    add( new LensFlareStripe() );
    add( new LensFlareApertureReflection() );
    add( new LensFlarePhotonSpikes( 5 ) );
    add( new LensFlareChromaHoop() );
    add( new LensFlareChromaFans() );
}


