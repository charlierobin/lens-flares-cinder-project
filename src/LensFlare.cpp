#include "LensFlare.hpp"
#include "LensFlareElement.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

LensFlare::LensFlare( std::string name )
{
    name_ = name;
    
    position_ = vec2( getWindowWidth() - 100, 100 );
    
    axis_ = vec2( getWindowSize().x / 2, getWindowSize().y / 2 );
    
    colour_ = Colorf( 1, 1, 1 );
    
    fallOff_ = nullptr;
}

void LensFlare::addFallOff( LensFlareFallOff * newValue )
{
    fallOff_ = newValue;
}

void LensFlare::add( LensFlareElement * element)
{
    elements_.push_back( element );
}

float LensFlare::getComputedIntensity()
{
    return computedIntensity_;
}

float LensFlare::getDistanceFromCentre()
{
    float xCentre = axis_.x;
    float yCentre = axis_.y;
    
    return hypot( xCentre - position_.x, yCentre - position_.y );
}

float LensFlare::getAngleFromCentre()
{
    float xCentre = axis_.x;
    float yCentre = axis_.y;
    
    return atan2( yCentre - position_.y, xCentre - position_.x );
}

float LensFlare::scaleBetween( float value, float upper, float lower )
{
    if ( value <= upper && value >= lower )
    {
        return ( value - lower ) / ( upper - lower );
    }
    else if ( value < lower )
    {
        return 0.0;
    }
    return 1.0;
}

vec2 LensFlare::getPositionOnAxis( float distanceOnAxis )
{
    float x = 0;
    float y = 0;
    
    float xOpposite = 0;
    float yOpposite = 0;
    
    float angle = 0;
    
    if ( position_.x < axis_.x && position_.y < axis_.y )
    {
        // top left
        
        x = axis_.x - position_.x;
        y = axis_.y - position_.y;
        
        xOpposite = axis_.x + x;
        yOpposite = axis_.y + y;
    }
    else if ( position_.x < axis_.x && position_.y > axis_.y )
    {
        // bottom left
        
        x = axis_.x - position_.x;
        y = position_.y - axis_.y;
        
        xOpposite = axis_.x + x;
        yOpposite = axis_.y - y;
    }
    else if ( position_.x > axis_.x && position_.y < axis_.y )
    {
        // top right
        
        x = position_.x - axis_.x;
        y = axis_.y - position_.y;
        
        xOpposite = axis_.x - x;
        yOpposite = axis_.y + y;
    }
    else
    {
        // bottom right
        
        x = position_.x - axis_.x;
        y = position_.y - axis_.y;
        
        xOpposite = axis_.x - x;
        yOpposite = axis_.y - y;
    }
    
    angle = atan2( y, x );
    
    float lengthOfAxis = 2 * hypot( x, y );
    
    float otherAngle = ( 3.14 / 2.0 ) - angle;
    
    float elementDistanceOnAxis = lengthOfAxis * distanceOnAxis;
    
    if ( position_.x < axis_.x && position_.y < axis_.y )
    {
        return vec2( position_.x + sin( otherAngle ) * elementDistanceOnAxis, position_.y + cos( otherAngle ) * elementDistanceOnAxis );
    }
    else if ( position_.x < axis_.x && position_.y > axis_.y )
    {
        return vec2( position_.x + sin( otherAngle ) * elementDistanceOnAxis, position_.y - cos( otherAngle ) * elementDistanceOnAxis);
    }
    else if ( position_.x > axis_.x && position_.y < axis_.y )
    {
        return vec2( position_.x - sin( otherAngle ) * elementDistanceOnAxis, position_.y + cos( otherAngle ) * elementDistanceOnAxis );
    }
    else
    {
        return vec2( position_.x - sin( otherAngle ) * elementDistanceOnAxis, position_.y - cos( otherAngle ) * elementDistanceOnAxis );
    }
}

void LensFlare::windowResized()
{
    if ( ! fallOff_ ) return;
    
    fallOff_->windowResized();
}

// draw with float -> intensity, draw with surface -> mask, to provide immediate rather than setting up FallOff etc ... ?

void LensFlare::draw()
{
    if ( fallOff_ )
    {
        computedIntensity_ = intensity_ * fallOff_->calculate( position_ );
        
        if ( invertFallOff_ ) computedIntensity_ = intensity_ - computedIntensity_;
    }
    else
    {
        computedIntensity_ = intensity_;
    }
    
    gl::setMatricesWindow( getWindowSize() );
    
    gl::disableDepthRead();
    gl::disableDepthWrite();
    
    gl::disableAlphaBlending();
    
    gl::enableAdditiveBlending();
    
    cinder::gl::color( 1, 1, 1, 1 );
    
    for ( auto element : elements_ )
    {
        gl::ScopedModelMatrix scope;
        
        element->draw( this );
    }
    
    gl::enableAlphaBlending();
}

void LensFlare::drawDebug()
{
    gl::setMatricesWindow( getWindowSize() );
    
    gl::disableDepthRead();
    gl::disableDepthWrite();
    
    cinder::gl::color( 1, 1, 1, 1 );
    
    // might draw some stuff here one day ...
    
    if ( ! fallOff_ ) return;
    
    fallOff_->drawDebug();
}



