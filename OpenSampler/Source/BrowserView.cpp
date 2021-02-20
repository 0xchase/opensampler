/*
  ==============================================================================

    BrowserView.cpp
    Created: 20 Feb 2021 5:03:19pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "BrowserView.h"

using namespace juce;

//==============================================================================
BrowserView::BrowserView()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    categoryBox.setBounds(20, 20, 190, 600);
    addAndMakeVisible(categoryBox);
    
    subCategoryBox.setBounds(220, 20, 190, 600);
    addAndMakeVisible(subCategoryBox);
    
    //moodBox.setBounds(420, 20, 190, 600);
    //addAndMakeVisible(moodBox);
    
    //authorBox.setBounds(20, 20, 200, 600);
    //addAndMakeVisible(authorBox);
    
    instrumentBox.setBounds(420, 20, 190, 600);
    addAndMakeVisible(instrumentBox);
    
    
    

}

BrowserView::~BrowserView()
{
}

void BrowserView::paint (juce::Graphics& g)
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
    g.drawText ("Browser View", getLocalBounds(), juce::Justification::centred, true);
}

void BrowserView::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
