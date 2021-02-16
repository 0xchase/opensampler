/*
  ==============================================================================

    BottomBar.cpp
    Created: 13 Feb 2021 2:02:56pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "BottomBar.h"

using namespace juce;

//==============================================================================
BottomBar::BottomBar()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    setSize(1180, 50);
    
    initPresetView();
    initMainView();
    initMidiEffectsView();
    initSamplerView();
    initAudioEffectsView();
}

BottomBar::~BottomBar()
{
}

void BottomBar::paint (juce::Graphics& g)
{

    const Rectangle<int32> area(0, 0, getWidth(), getHeight());
    const Rectangle<float> areaFix = area.toFloat();
    g.setColour(juce::Colour::fromRGB(54, 54, 54));
    g.fillRoundedRectangle(areaFix, 15.0f);
    
    g.setFont (14.0f);
    g.drawText ("BottomBar", getLocalBounds(), juce::Justification::centred, true);
}

void BottomBar::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..


}

