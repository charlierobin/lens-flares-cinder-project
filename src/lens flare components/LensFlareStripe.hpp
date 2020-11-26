#ifndef LensFlareStripe_hpp
#define LensFlareStripe_hpp

#include "LensFlareElement.hpp"

class LensFlareStripe: public LensFlareElement {
    
public:
    
    LensFlareStripe();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 2;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareStripe_hpp */
