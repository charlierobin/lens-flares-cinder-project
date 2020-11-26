#ifndef LensFlareFallOffPoint_hpp
#define LensFlareFallOffPoint_hpp

#include "LensFlareFallOff.hpp"

class LensFlareFallOffPoint : public LensFlareFallOff {
    
public:
    
    LensFlareFallOffPoint();
    
    float calculate( cinder::vec2 ) override;
    
private:
    
    cinder::vec2 point_;
    
    float maxDistance_;
};

#endif /* LensFlareFallOffPoint_hpp */
