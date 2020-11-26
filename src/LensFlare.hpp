#ifndef LensFlare_hpp
#define LensFlare_hpp

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "LensFlareFallOff.hpp"

class LensFlareElement;

class LensFlare {
    
public:
    
    LensFlare();
    
    void add( LensFlareElement * );
    
    void draw();
    void drawDebug();
    
    void setPosition( cinder::vec2 );
    void setAxis( cinder::vec2 );
    
    void addFallOff( LensFlareFallOff * );
    void setInvertFallOff( bool );
    
    float getIntensity();
    void setIntensity( float );
    
    float getComputedIntensity();
    
    cinder::vec2 getPosition();
    cinder::vec2 getAxis();
    
    float getAngle();
    void setAngle( float );
    
    cinder::vec2 getPositionOnAxis( float );
    
    float getDistanceFromCentre();
    float getAngleFromCentre();
    float scaleBetween( float, float, float );
    
    void windowResized();
    
private:
    
    cinder::vec2 position_;
    cinder::vec2 axis_;
    float angle_ = 0.0;
    
    std::vector<LensFlareElement *> elements_;
    
    float intensity_ = 1.0;
    float computedIntensity_ = 0.0;
    
    LensFlareFallOff * fallOff_;
    
    bool invertFallOff_ = false;
};

#endif /* LensFlare_hpp */
