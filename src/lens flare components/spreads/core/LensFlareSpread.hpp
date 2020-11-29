#ifndef LensFlareSpread_hpp
#define LensFlareSpread_hpp

#include "LensFlareElement.hpp"

class LensFlareSpreadElement;

class LensFlareSpread: public LensFlareElement {
    
public:
    
    LensFlareSpread( int, std::string );
    
    void draw( LensFlare * ) override;
    
    void ui() override;
    
    std::vector<LensFlareSpreadElement *> elements_;
    
    cinder::Color colour_;
    
    bool useColour_ = false;
    
    float colourVariationRange_ = 0;
};

#endif /* LensFlareSpread_hpp */
