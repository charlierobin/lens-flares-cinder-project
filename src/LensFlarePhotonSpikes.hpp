#ifndef LensFlarePhotonSpikes_hpp
#define LensFlarePhotonSpikes_hpp

#include "LensFlareElement.hpp"
#include "LensFlarePhotonSpike.hpp"

class LensFlarePhotonSpikes: public LensFlareElement {
    
public:
    
    LensFlarePhotonSpikes( int );
    
    void draw( LensFlare * ) override;
    
    std::vector<LensFlarePhotonSpike *> spikes_;
    
};


#endif /* LensFlarePhotonSpikes_hpp */
