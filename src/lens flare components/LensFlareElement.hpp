#ifndef LensFlareElement_hpp
#define LensFlareElement_hpp

#include "cinder/Rand.h"

#include "LensFlare.hpp"

class LensFlareElement {
    
public:
    
    virtual void draw( LensFlare * );
    
};

#endif /* LensFlareElement_hpp */
