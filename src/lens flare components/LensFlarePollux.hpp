#ifndef LensFlarePollux_hpp
#define LensFlarePollux_hpp

#include "LensFlareElement.hpp"

class LensFlarePollux: public LensFlareElement {
    
public:
    
    LensFlarePollux();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
    
    cinder::gl::Texture2dRef textureFG_;
    cinder::gl::Texture2dRef textureBG_;
    
};

#endif /* LensFlarePollux_hpp */
