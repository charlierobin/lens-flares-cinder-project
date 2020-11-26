#ifndef LensFlareFallOffImage_hpp
#define LensFlareFallOffImage_hpp

#include "LensFlareFallOff.hpp"

#include "cinder/ip/Resize.h"

class LensFlareFallOffImage : public LensFlareFallOff {
    
public:
    
    LensFlareFallOffImage();
    LensFlareFallOffImage( std::string );
    
    float calculate( cinder::vec2 ) override;
    
    void setImage( cinder::Surface );
    
    void setImage( std::string );
    
    void drawDebug() override;
    
    void windowResized() override;
    
private:
    
    cinder::Surface surface_;
    
    float radius_;
    
};

#endif /* LensFlareFallOffImage_hpp */
