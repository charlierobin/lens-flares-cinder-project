#ifndef CustomLensFlare_hpp
#define CustomLensFlare_hpp

#include "LensFlare.hpp"

#include "LensFlareCentralGlow.hpp"
#include "LensFlareStripe.hpp"
#include "LensFlarePolygonSpread.hpp"
#include "LensFlareApertureReflection.hpp"
#include "LensFlarePhotonSpikes.hpp"
#include "LensFlareChromaHoop.hpp"
#include "LensFlareChromaFans.hpp"

class CustomLensFlare: public LensFlare {
    
public:
    
    CustomLensFlare();
    
};

#endif /* CustomLensFlare_hpp */
