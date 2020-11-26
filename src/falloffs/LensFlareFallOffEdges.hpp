#ifndef LensFlareFallOffEdges_hpp
#define LensFlareFallOffEdges_hpp

#include "LensFlareFallOff.hpp"

class LensFlareFallOffEdges : public LensFlareFallOff {
    
public:
    
    LensFlareFallOffEdges();
    
    float calculate( cinder::vec2 ) override;
    
private:
    
    float margin_;
};

#endif /* LensFlareFallOffEdges_hpp */
