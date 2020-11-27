#ifndef LensFlareCentralRandomFan_hpp
#define LensFlareCentralRandomFan_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralRandomFan: public LensFlareElement {
    
public:
    
    LensFlareCentralRandomFan();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 0.5;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentralRandomFan_hpp */
