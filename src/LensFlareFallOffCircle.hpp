#ifndef LensFlareFallOffCircle_hpp
#define LensFlareFallOffCircle_hpp

#include "LensFlareFallOff.hpp"

class LensFlareFallOffCircle : public LensFlareFallOff {
    
public:
    
    LensFlareFallOffCircle();
    
    float calculate( cinder::vec2 ) override;
    
private:
    
    cinder::vec2 centre_;
    
    float radius_;
};

#endif /* LensFlareFallOffCircle_hpp */
