#ifndef LensFlareCentralGlow_hpp
#define LensFlareCentralGlow_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralGlow: public LensFlareElement {
    
public:
    
    LensFlareCentralGlow();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 0.5f;
    
    cinder::gl::Texture2dRef texture_;
    
    float width_ = 1024;
    float height_ = 1024;
};

#endif /* LensFlareCentralGlow_hpp */
