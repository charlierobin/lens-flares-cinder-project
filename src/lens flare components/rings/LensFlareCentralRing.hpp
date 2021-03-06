#ifndef LensFlareCentralRing_hpp
#define LensFlareCentralRing_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralRing: public LensFlareElement {
    
public:
    
    LensFlareCentralRing();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentralRing_hpp */
