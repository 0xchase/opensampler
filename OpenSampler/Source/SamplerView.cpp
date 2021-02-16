/*
  ==============================================================================

    SamplerView.cpp
    Created: 16 Feb 2021 4:16:30pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SamplerView.h"

using namespace juce;

//==============================================================================
SamplerView::SamplerView()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

SamplerView::~SamplerView()
{
}

void SamplerView::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    const Rectangle<int32> area(0, 0, getWidth(), getHeight());
    const Rectangle<float> areaFix = area.toFloat();
    g.setColour(juce::Colour::fromRGB(54, 54, 54));
    g.fillRoundedRectangle(areaFix, 15.0f);
    
    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("Sampler View", getLocalBounds(), juce::Justification::centred, true);
}

void SamplerView::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
