#ifndef LensFlareCentralPolySpike_hpp
#define LensFlareCentralPolySpike_hpp

#include "LensFlareElement.hpp"

class LensFlareCentralPolySpike: public LensFlareElement {
    
public:
    
    LensFlareCentralPolySpike();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 0.5;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareCentralPolySpike_hpp */
