#ifndef LensFlareCentralGlow_hpp
#define LensFlareCentralGlow_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralGlow: public LensFlareElement {
    
public:
    
    LensFlareCentralGlow();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 0.5;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentralGlow_hpp */
