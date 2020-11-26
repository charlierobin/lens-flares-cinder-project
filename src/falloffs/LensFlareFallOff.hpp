#ifndef LensFlareFallOff_hpp
#define LensFlareFallOff_hpp

class LensFlareFallOff {
    
public:
    
    virtual float calculate( cinder::vec2 );
    
    virtual void drawDebug();
    
    virtual void windowResized();
};

#endif /* LensFlareFallOff_hpp */
