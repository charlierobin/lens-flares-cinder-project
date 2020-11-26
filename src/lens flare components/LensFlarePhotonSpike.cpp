#include "LensFlarePhotonSpike.hpp"

using namespace ci;
using namespace ci::app;

LensFlarePhotonSpike::LensFlarePhotonSpike()
{
    Surface img = loadImage( loadResource( "photon-spike.jpg" ) );
    
    texture_ = gl::Texture::create( img );
    
    angle_ = randFloat( 0, 3.14 * 2 );
    
    scale_ = randFloat( 0.7, 1.1 );
}

void LensFlarePhotonSpike::draw( LensFlare * flare )
{
    float scaledWidth = 1024 * scale_ * flare->getComputedIntensity();
    float scaledHeight = 256 * scale_ * flare->getComputedIntensity();
    
    gl::ScopedModelMatrix scope;
    
    gl::ScopedColor color( 1, 1, 1, 1 );
    
    gl::translate( flare->getPosition() );
    
    gl::rotate( angle_ + flare->getAngle() );
    
    gl::draw( texture_, Rectf( 0, - scaledHeight / 2, scaledWidth, scaledHeight / 2 ) );
}

