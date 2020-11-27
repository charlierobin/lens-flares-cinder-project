#ifndef LensFlareCentralRingFilled_hpp
#define LensFlareCentralRingFilled_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralRingFilled: public LensFlareElement {
    
public:
    
    LensFlareCentralRingFilled();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
    
    const float size_ = 512;
};

#endif /* LensFlareCentralRingFilled_hpp */
