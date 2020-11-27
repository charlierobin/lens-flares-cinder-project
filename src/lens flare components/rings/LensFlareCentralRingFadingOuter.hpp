#ifndef LensFlareCentralRingFadingOuter_hpp
#define LensFlareCentralRingFadingOuter_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralRingFadingOuter: public LensFlareElement {
    
public:
    
    LensFlareCentralRingFadingOuter();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
    
    const float size_ = 512;
};

#endif /* LensFlareCentralRingFadingOuter_hpp */
