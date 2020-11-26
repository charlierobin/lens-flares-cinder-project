#ifndef LensFlarePhotonSpike_hpp
#define LensFlarePhotonSpike_hpp

#include "LensFlareElement.hpp"

class LensFlarePhotonSpike: public LensFlareElement {
    
public:
    
    LensFlarePhotonSpike();
    
    void draw( LensFlare * ) override;
    
private:
    
    float scale_ = 1;
    
    float angle_ = 0;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlarePhotonSpike_hpp */
