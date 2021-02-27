/*
  ==============================================================================

    ModuleDraggable.cpp
    Created: 26 Feb 2021 9:20:50pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ModuleDraggable.h"

using namespace juce;

//==============================================================================
ModuleDraggable::ModuleDraggable()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

ModuleDraggable::~ModuleDraggable()
{
    
}

void ModuleDraggable::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("DragMe", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void ModuleDraggable::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void ModuleDraggable::mouseDrag(const MouseEvent& event) {
    juce::DragAndDropContainer* dragC = juce::DragAndDropContainer::findParentDragContainerFor(this);
    
    if (!dragC) {
        std::cout << "TargetSource::mouseDrag(): can't find parent drag container" << std::endl;
    } else {
        if (!dragC->isDragAndDropActive())
        {
            dragC->startDragging("TargetSource", this);
        }
    }
}
