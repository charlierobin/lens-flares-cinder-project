#include "CustomLensFlare3.hpp"

CustomLensFlare3::CustomLensFlare3(): LensFlare( "CustomLensFlare3" )
{
    // "prefab" centres
    
    //add( new LensFlareCentrePreComp1() );
    add( new LensFlarePollux() );
    
    // more basic centre elements designed for combining
    
    //add( new LensFlareCentralGlow() );
    //add( new LensFlareCentralSpikeBall() );
    //add( new LensFlareCentralDisc() );
//    add( new LensFlareCentralPolySpike() );
    add( new LensFlareCentralRandomFan() );
    
    // rings
    
    //add( new LensFlareCentralRing() );
    add( new LensFlareCentralRingFadingInner() );
    //add( new LensFlareCentralRingFadingOuter() );
    //add( new LensFlareCentralRingFilled() );
    
    // spreads along axis from light source
    
//    add( new LensFlareSpreadPentagons( 11 ) );
    //add( new LensFlareSpreadOctagons( 3 ) );
    add( new LensFlareSpreadCircles( 15 ) );
    
    // adornments, miscellaneous
    
    add( new LensFlareStripe() );
    //add( new LensFlareApertureReflection() );
    add( new LensFlarePhotonSpikes( 15 ) );
    add( new LensFlareChromaHoop() );
    //add( new LensFlareChromaFans() );
    
    
    // special
    
//    add( new LensFlareSunDogs() );
    
    colour_ = ci::Colorf( 1, 0, 0 );
}


