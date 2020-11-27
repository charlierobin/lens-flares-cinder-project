#ifndef LensFlareSpread_hpp
#define LensFlareSpread_hpp

#include "LensFlareElement.hpp"

class LensFlareSpreadElement;

class LensFlareSpread: public LensFlareElement {
    
public:
    
    LensFlareSpread( int, std::string );
    
    void draw( LensFlare * ) override;
    
    std::vector<LensFlareSpreadElement *> elements_;
    
};

#endif /* LensFlareSpread_hpp */
