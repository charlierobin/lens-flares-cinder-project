#ifndef LensFlare_hpp
#define LensFlare_hpp

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/ip/Resize.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LensFlare {
    
public:
    
    LensFlare();
    
    void draw();
    
    void setPosition( vec2 );
    
    void setMask( Surface* );
    
private:
    
    vec2 m_position;
    
    float intensity_ = 1.0;
    
    gl::Texture2dRef texture_;
    
    bool invert = true;
    
    enum class FallOffs {
        
        none,
        point,
        circle,
        image
        
    };
    
    FallOffs fallOff_ = FallOffs::none;
    
    vec2 m_fallOffPoint;
    float m_fallOffRadius;
    
    Surface* intensityMap_;
};

#endif /* LensFlare_hpp */
