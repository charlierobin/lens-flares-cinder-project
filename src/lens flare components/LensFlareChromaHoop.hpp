#ifndef LensFlareChromaHoop_hpp
#define LensFlareChromaHoop_hpp

#include "LensFlareElement.hpp"

class LensFlareChromaHoop: public LensFlareElement {
    
public:
    
    LensFlareChromaHoop();
    
    void draw( LensFlare * ) override;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareChromaHoop_hpp */
