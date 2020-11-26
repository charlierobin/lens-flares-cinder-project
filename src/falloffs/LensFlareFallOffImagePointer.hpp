#ifndef LensFlareFallOffImagePointer_hpp
#define LensFlareFallOffImagePointer_hpp

#include "LensFlareFallOff.hpp"

#include "cinder/ip/Resize.h"

class LensFlareFallOffImagePointer : public LensFlareFallOff {
    
public:
    
    LensFlareFallOffImagePointer();
    
    float calculate( cinder::vec2 ) override;
    
    void set( cinder::Surface * );
    
    void drawDebug() override;
    
private:
    
    cinder::Surface * surface_;
    
    float radius_;
    
};

#endif /* LensFlareFallOffImagePointer_hpp */
