#ifndef LensFlareSpreadElement_hpp
#define LensFlareSpreadElement_hpp

#include "LensFlare.hpp"
#include "LensFlareSpread.hpp"

class LensFlareSpreadElement {
    
public:
    
    LensFlareSpreadElement( std::string );
    
    void draw( LensFlareSpread *, LensFlare * );
    
private:
    
    float positionOnAxis_ = 1;
    
    float scale_ = 1;
    
    float alpha_ = 0.2;
    
    cinder::gl::Texture2dRef texture_;
};

#endif /* LensFlareSpreadElement_hpp */
