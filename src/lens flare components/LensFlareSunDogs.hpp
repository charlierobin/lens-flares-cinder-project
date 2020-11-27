#ifndef LensFlareSunDogs_hpp
#define LensFlareSunDogs_hpp

#include "LensFlareElement.hpp"

class LensFlareSunDogs: public LensFlareElement {
    
public:
    
    LensFlareSunDogs();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef textureRing_;
    cinder::gl::Texture2dRef textureSide_;
    
    cinder::gl::Texture2dRef textureSpike_;
    
    cinder::gl::Texture2dRef textureCentre_;
};

#endif /* LensFlareSunDogs_hpp */
