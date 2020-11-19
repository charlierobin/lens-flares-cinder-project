#include "LensFlare.hpp"

LensFlare::LensFlare()
{
    Surface img = loadImage( loadResource( "centre-1.jpg" ) );
    
    texture_ = gl::Texture::create( img );
    
    //
    
    fallOff_ = FallOffs::image;
    
    m_fallOffPoint = vec2( getWindowWidth() / 2, getWindowHeight() / 2 );
    m_fallOffRadius = 150.0f;
    
    Surface surfaceOriginal = loadImage( loadResource( "grey-scale-photo.jpg" ) );
    
    Surface surfaceResized = Surface8u( getWindowWidth(), getWindowHeight(), false );
    
    ip::resize( surfaceOriginal, &surfaceResized );
    
    intensityMap_ = &surfaceResized;
}

void LensFlare::setPosition( vec2 position )
{
    m_position = position;
}

void LensFlare::setMask( Surface* newMap )
{
    intensityMap_ = newMap;
}

// draw with float -> intensity, draw with surface -> mask

void LensFlare::draw()
{
    // falloffs: from a point, above/below a horiz, left/right a vertical, a rect, a circle, texture ... manual ?
    
    switch ( fallOff_ ) {
            
        case FallOffs::point:
        {
            float distance = sqrt( pow ( m_position.x - m_fallOffPoint.x, 2 ) + pow ( m_position.y - m_fallOffPoint.y, 2 ) );
            
            intensity_ = distance  / 200.0f;
            
            break;
        }
            
        case FallOffs::circle:
        {
            float distance = sqrt( pow ( m_position.x - m_fallOffPoint.x, 2 ) + pow ( m_position.y - m_fallOffPoint.y, 2 ) );
            
            if ( distance > m_fallOffRadius )
            {
                intensity_ = 1.0f;
            }
            else
            {
                intensity_ = 0.0f;
            }
            
            break;
        }
            
        case FallOffs::image:
        {
            auto sample = intensityMap_->getPixel( m_position );
            
            intensity_ = sample.r / 255.0f;
            
            break;
        }
            
        case FallOffs::none:
        {
            // nothing
        }
    }
    
    if ( invert ) intensity_ = 1.0f - intensity_;
    
    float scaledWidth = 1024 * intensity_;
    float scaledHeight = 1024 * intensity_;
    
    gl::setMatricesWindow( getWindowSize() );
    
    gl::disableAlphaBlending();
    
    gl::enableAdditiveBlending();
    
    cinder::gl::color( 1.0, 1.0, 1.0, 1.0 );
    
    gl::pushModelView();
    
    gl::translate( m_position.x, m_position.y );
    
    gl::translate( - scaledWidth / 2, - scaledHeight / 2 );
    
    gl::draw( texture_, Rectf( 0, 0, scaledWidth, scaledHeight ) );
    
    gl::enableAlphaBlending();
    
    gl::popModelView();
}


