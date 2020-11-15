#ifndef LensFlare_hpp
#define LensFlare_hpp

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LensFlare {
    
public:
    
    LensFlare();
    
    void draw();
    
    void setPosition( vec2 );
    
private:
    
    vec2 m_position;
    
    float intensity_ = 1.0;
    
    gl::Texture2dRef texture_;
};

#endif /* LensFlare_hpp */
