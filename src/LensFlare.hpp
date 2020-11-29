#ifndef LensFlare_hpp
#define LensFlare_hpp

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "LensFlareFallOff.hpp"

class LensFlareElement;

class LensFlare {
    
public:
    
    LensFlare() : LensFlare( "no name" ){};
    LensFlare( std::string );
    
    void add( LensFlareElement * );
    
    void draw();
    void drawDebug();
    
    void addFallOff( LensFlareFallOff * );
    
    float getComputedIntensity();
    
    cinder::vec2 getPositionOnAxis( float );
    
    float getDistanceFromCentre();
    float getAngleFromCentre();
    float scaleBetween( float, float, float );
    
    void windowResized();
    
    std::vector<LensFlareElement *> getElements();
    
    std::string name_;
    
    cinder::vec2 position_;
    cinder::vec2 axis_;
    float intensity_ = 1;
    float angle_ = 0;
    cinder::Color colour_;
    bool invertFallOff_ = false;
    
private:
    
    std::vector<LensFlareElement *> elements_;
    
    float computedIntensity_ = 0;
    
    LensFlareFallOff * fallOff_;
};

#endif /* LensFlare_hpp */
