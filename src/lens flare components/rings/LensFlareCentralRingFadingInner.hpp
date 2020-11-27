#ifndef LensFlareCentralRingFadingInner_hpp
#define LensFlareCentralRingFadingInner_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralRingFadingInner: public LensFlareElement {
    
public:
    
    LensFlareCentralRingFadingInner();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentralRingFadingInner_hpp */
