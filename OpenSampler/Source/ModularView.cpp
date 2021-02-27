/*
  ==============================================================================

    ModularView.cpp
    Created: 16 Feb 2021 4:17:09pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ModularView.h"

using namespace juce;

//==============================================================================
ModularView::ModularView()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    addAndMakeVisible(patchingView);
    addAndMakeVisible(modulesListView);
    
    resized();
}

ModularView::~ModularView()
{
    /*
    for (auto module : modules) {
        delete module;
    }
     */
}

void ModularView::paint (juce::Graphics& g)
{
    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("Modular View", getLocalBounds(), juce::Justification::centred, true);
}

void ModularView::resized()
{
    patchingView.setBounds(0, 0, getWidth()-50-120, getHeight());
    modulesListView.setBounds(getWidth()-65-100, 0, 165, getHeight());


}
