#ifndef CustomLensFlare_hpp
#define CustomLensFlare_hpp

#include "LensFlare.hpp"

#include "LensFlareCentrePreComp1.hpp"

#include "LensFlareCentralGlow.hpp"
#include "LensFlareCentralSpikeBall.hpp"
#include "LensFlareCentralDisc.hpp"
#include "LensFlareCentralPolySpike.hpp"
#include "LensFlareCentralRandomFan.hpp"

#include "LensFlareSpreadPentagons.hpp"
#include "LensFlareSpreadOctagons.hpp"
#include "LensFlareSpreadCircles.hpp"



#include "LensFlareStripe.hpp"

#include "LensFlareApertureReflection.hpp"
#include "LensFlarePhotonSpikes.hpp"
#include "LensFlareChromaHoop.hpp"
#include "LensFlareChromaFans.hpp"
#include "LensFlareCentralRing.hpp"
#include "LensFlareCentralRingFadingInner.hpp"
#include "LensFlareCentralRingFadingOuter.hpp"
#include "LensFlareCentralRingFilled.hpp"

#include "LensFlareSunDogs.hpp"

class CustomLensFlare: public LensFlare {
    
public:
    
    CustomLensFlare();
    
};

#endif /* CustomLensFlare_hpp */
