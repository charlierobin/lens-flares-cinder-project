#include "LensFlare.hpp"

LensFlare::LensFlare()
{
    Surface img = loadImage( loadResource( "centre-1.jpg" ) );
    
    texture_ = gl::Texture::create( img );
}

void LensFlare::setPosition( vec2 position )
{
    m_position = position;
}

void LensFlare::draw()
{
  
    
    float scaledWidth = 1024 * intensity_;
    float scaledHeight = 1024 * intensity_;
    
    gl::setMatricesWindow( getWindowSize() );
    
    //    gl::disableDepthRead();
    //    gl::disableDepthWrite();
    
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


