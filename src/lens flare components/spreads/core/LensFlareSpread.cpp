#include "LensFlareSpread.hpp"

#include "LensFlareSpreadElement.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

LensFlareSpread::LensFlareSpread( int numberOfElements, std::string resourceName )
{
    for ( int i = 0; i < numberOfElements; ++i )
    {
        elements_.push_back( new LensFlareSpreadElement( resourceName ) );
    }
}

void LensFlareSpread::draw( LensFlare * flare )
{
    for ( auto element : elements_ )
    {
        element->draw( this, flare );
    }
}

void LensFlareSpread::ui()
{
    if ( ImGui::TreeNode( "Spread element" ) )
    {
        float colourVariationRange = colourVariationRange_;
        
        ImGui::SliderFloat( "Variation", &colourVariationRange_, 0.0, 1.0 );
        
        if ( colourVariationRange_ != colourVariationRange )
        {
            for ( auto element : elements_ )
            {
                element->generateColourVariation( colourVariationRange_ );
            }
        }
        
        ImGui::Checkbox( "Use colour", &useColour_ );
        
        ImGui::ColorPicker3( "Colour", &colour_ );
        
        ImGui::TreePop();
    }
}

