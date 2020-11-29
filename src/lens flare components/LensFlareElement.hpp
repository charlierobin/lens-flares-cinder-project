#ifndef LensFlareElement_hpp
#define LensFlareElement_hpp

#include "cinder/Rand.h"
#include "cinder/CinderImGui.h"

#include "LensFlare.hpp"

class LensFlareElement {
    
public:
    
    virtual void draw( LensFlare * );
    
    virtual void ui();
    
};

#endif /* LensFlareElement_hpp */
