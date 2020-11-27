#ifndef LensFlareCentrePreComp1_hpp
#define LensFlareCentrePreComp1_hpp

#include "LensFlareElement.hpp"

class LensFlareCentrePreComp1: public LensFlareElement {
    
public:
    
    LensFlareCentrePreComp1();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 0.5;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentrePreComp1_hpp */
