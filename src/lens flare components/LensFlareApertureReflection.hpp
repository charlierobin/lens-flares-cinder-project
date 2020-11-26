#ifndef LensFlareApertureReflection_hpp
#define LensFlareApertureReflection_hpp

#include "LensFlareElement.hpp"

class LensFlareApertureReflection: public LensFlareElement {
    
public:
    
    LensFlareApertureReflection();
    
    void draw( LensFlare * ) override;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
    
private:
    
    float calculateScale( float );
    
};

#endif /* LensFlareApertureReflection_hpp */
