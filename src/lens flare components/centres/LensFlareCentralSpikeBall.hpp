#ifndef LensFlareCentralSpikeBall_hpp
#define LensFlareCentralSpikeBall_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralSpikeBall: public LensFlareElement {
    
public:
    
    LensFlareCentralSpikeBall();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 0.5;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentralSpikeBall_hpp */
