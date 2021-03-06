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
    float scaledWidth = texture_->getWidth() * scale_ * flare->getComputedIntensity();
    float scaledHeight = texture_->getHeight() * scale_ * flare->getComputedIntensity();
    
    gl::ScopedModelMatrix scope;
    
    gl::ScopedColor color( 1, 1, 1, 1 );
    
    gl::translate( flare->position_ );
    
    gl::rotate( angle_ + flare->angle_ );
    
    gl::draw( texture_, Rectf( 0, - scaledHeight / 2, scaledWidth, scaledHeight / 2 ) );
}

