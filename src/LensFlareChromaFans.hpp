#ifndef LensFlareChromaFans_hpp
#define LensFlareChromaFans_hpp

#include "LensFlareElement.hpp"

class LensFlareChromaFans: public LensFlareElement {
    
public:
    
    LensFlareChromaFans();
    
    void draw( LensFlare * ) override;
    
private:
    
    float angle_ = 3.14 / 2;
    
    float scale_ = 0.5;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareChromaFans_hpp */

