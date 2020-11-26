#ifndef LensFlarePolygonSpread_hpp
#define LensFlarePolygonSpread_hpp

#include "LensFlareElement.hpp"
#include "LensFlarePolygon.hpp"

class LensFlarePolygonSpread: public LensFlareElement {
    
public:
    
    LensFlarePolygonSpread( int );
    
    void draw( LensFlare * ) override;
    
    std::vector<LensFlarePolygon *> polygons_;

};

#endif /* LensFlarePolygonSpread_hpp */
