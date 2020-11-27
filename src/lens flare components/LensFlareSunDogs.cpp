#include "LensFlareSunDogs.hpp"

using namespace ci;
using namespace ci::app;

LensFlareSunDogs::LensFlareSunDogs()
{
    textureRing_ = gl::Texture::create( loadImage( loadResource( "fading-ring-outer.jpg" ) ) );
    
    textureSide_ = gl::Texture::create( loadImage( loadResource( "sundog-side.jpg" ) ) );
    
    textureSpike_ = gl::Texture::create( loadImage( loadResource( "photon-spike.jpg" ) ) );
    
    textureCentre_ = gl::Texture::create( loadImage( loadResource( "sundog-centre.jpg" ) ) );
}

void LensFlareSunDogs::draw( LensFlare * flare )
{
    float ringScale = 2.0;
    
    {
        gl::ScopedModelMatrix scope;
        
        gl::ScopedColor colour( 1, 1, 1, 0.5 );
    
        float scaled = ringScale * textureRing_->getWidth() * scale_ * flare->getComputedIntensity();
        
        gl::translate( flare->getPosition() );
        
        gl::draw( textureRing_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
    }
    
    {
        gl::ScopedModelMatrix scope;
        
        gl::ScopedColor colour( 1, 1, 1, 0.5 );
        
        float scaled = textureSide_->getWidth() * scale_ * flare->getComputedIntensity();
        
        gl::translate( flare->getPosition() );
        
        
        float scaleFactor1 = ringScale * scale_ * flare->getComputedIntensity();
        float scaleFactor2 = scale_ * flare->getComputedIntensity();
        
        
        gl::translate( vec2( ( ( ( 466 - 256 ) * scaleFactor1 ) + ( ( 256 - 113 ) * scaleFactor2 ) ), 0 ) );
        
        gl::draw( textureSide_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
        
        
        gl::translate( vec2( - ( ( ( 466 - 45 ) * scaleFactor1 ) + ( 290 * scaleFactor2 ) ), 0 ) );
        
        gl::draw( textureSide_, Rectf( scaled / 2, scaled / 2, - scaled / 2, - scaled / 2 ) );
    }
    
    {
        gl::ScopedModelMatrix scope;
        
        gl::ScopedColor colour( 1, 1, 1, 0.5 );
        
        float scaledWidth = textureSpike_->getWidth() * scale_ * flare->getComputedIntensity();
        float scaledHeight = textureSpike_->getHeight() * scale_ * flare->getComputedIntensity();
        
        gl::translate( flare->getPosition() );
        
        gl::rotate( M_PI / 2 );
        
        gl::draw( textureSpike_, Rectf( 0, - scaledHeight / 2, scaledWidth, scaledHeight / 2 ) );
        
        gl::rotate( M_PI );
        
        gl::draw( textureSpike_, Rectf( 0, - scaledHeight / 2, scaledWidth, scaledHeight / 2 ) );
    }
    
    {
        gl::ScopedModelMatrix scope;
        
        float scaledWidth = textureSpike_->getWidth() * scale_ * flare->getComputedIntensity();
        float scaledHeight = textureSpike_->getHeight() * scale_ * flare->getComputedIntensity();
        
        gl::translate( flare->getPosition() );
        
        gl::draw( textureSpike_, Rectf( 0, - scaledHeight / 4, scaledWidth, scaledHeight / 4 ) );
        
        gl::rotate( M_PI );
        
        gl::draw( textureSpike_, Rectf( 0, - scaledHeight / 4, scaledWidth, scaledHeight / 4 ) );
    }
    
    {
        gl::ScopedModelMatrix scope;
        
        float scaled = 0.7 * textureCentre_->getWidth() * scale_ * flare->getComputedIntensity();
        
        gl::translate( flare->getPosition() );
        
        gl::draw( textureCentre_, Rectf( - scaled / 2, - scaled / 2, scaled / 2, scaled / 2 ) );
    }
}

// ring, two bits on each side, central pillar, etc ? cross?



