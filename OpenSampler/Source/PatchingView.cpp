/*
  ==============================================================================

    PatchingView.cpp
    Created: 26 Feb 2021 8:38:48pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PatchingView.h"
#include "Module.h"

using namespace juce;

//==============================================================================
PatchingView::PatchingView()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
}

PatchingView::~PatchingView()
{
}

void PatchingView::addModule(String name, int x, int y) {
    Module * tempModule = new Module();
    tempModule->setBounds(x, y, 50, 50);
    
    addAndMakeVisible(tempModule);
    
    modules.push_back(tempModule);
}

void PatchingView::paint (juce::Graphics& g)
{

    const Rectangle<int32> area(0, 0, getWidth(), getHeight());
    const Rectangle<float> areaFix = area.toFloat();
    g.setColour(juce::Colour::fromRGB(54, 54, 54));
    g.fillRoundedRectangle(areaFix, 15.0f);
    
    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("Patching", getLocalBounds(), juce::Justification::centred, true);
}

void PatchingView::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


