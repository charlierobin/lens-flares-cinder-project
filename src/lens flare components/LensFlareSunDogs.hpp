#ifndef LensFlareSunDogs_hpp
#define LensFlareSunDogs_hpp

#include "LensFlareElement.hpp"

class LensFlareSunDogs: public LensFlareElement {
    
public:
    
    LensFlareSunDogs();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
    
    const float size_ = 512;
};

#endif /* LensFlareSunDogs_hpp */