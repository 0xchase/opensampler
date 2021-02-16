/*
  ==============================================================================

    TopBar.cpp
    Created: 13 Feb 2021 2:02:34pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TopBar.h"

//==============================================================================
TopBar::TopBar()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

TopBar::~TopBar()
{
}

void TopBar::paint (juce::Graphics& g)
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

    g.setFont (14.0f);
    g.drawText ("TopBar", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void TopBar::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
