/*
  ==============================================================================

    ModulesListView.cpp
    Created: 26 Feb 2021 8:39:58pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ModulesListView.h"

using namespace juce;

//==============================================================================
ModulesListView::ModulesListView()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    testModule.setBounds(5, 5, 50, 50);
    addAndMakeVisible(testModule);
}

ModulesListView::~ModulesListView()
{
}

void ModulesListView::paint (juce::Graphics& g)
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
    g.drawText ("Modules List", getLocalBounds(), juce::Justification::centred, true);
}

void ModulesListView::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
