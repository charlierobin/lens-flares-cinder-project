#ifndef LensFlareCentralDisc_hpp
#define LensFlareCentralDisc_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralDisc: public LensFlareElement {
    
public:
    
    LensFlareCentralDisc();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 0.5;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentralDisc_hpp */
