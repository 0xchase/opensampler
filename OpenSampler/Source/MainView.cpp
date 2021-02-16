/*
  ==============================================================================

    MainView.cpp
    Created: 13 Feb 2021 1:20:58pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MainView.h"

using namespace juce;

//==============================================================================
MainView::MainView() :  keyboardComponent (keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    //createButton(100, 100, 100, 100);
    keyboardComponent.setBounds(100, 700, 800, 60);
    addAndMakeVisible (keyboardComponent);
    keyboardState.addListener (this);
    
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setRange(0.1f, 10.0f);
    slider.setValue(0.1f);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    slider.setBounds(200, 200, 100, 300);

    addAndMakeVisible(&slider);

}

MainView::~MainView()
{
    
}

void MainView::paint (juce::Graphics& g)
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
    g.drawText ("MainView", getLocalBounds(), juce::Justification::centred, true);
}

void MainView::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
