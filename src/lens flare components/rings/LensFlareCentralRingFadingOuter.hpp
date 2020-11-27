#ifndef LensFlareCentralRingFadingOuter_hpp
#define LensFlareCentralRingFadingOuter_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralRingFadingOuter: public LensFlareElement {
    
public:
    
    LensFlareCentralRingFadingOuter();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentralRingFadingOuter_hpp */
