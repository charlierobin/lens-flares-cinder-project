#ifndef LensFlarePolygon_hpp
#define LensFlarePolygon_hpp

#include "LensFlareElement.hpp"

class LensFlarePolygon: public LensFlareElement {
    
public:
    
    LensFlarePolygon();
    
    void draw( LensFlare * ) override;
    
private:
    
    float positionOnAxis_ = 1;
    
    float scale_ = 1;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlarePolygon_hpp */
