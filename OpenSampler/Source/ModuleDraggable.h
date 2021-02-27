/*
  ==============================================================================

    ModuleDraggable.h
    Created: 26 Feb 2021 9:20:50pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//using namespace juce;
//==============================================================================
/*
*/
class ModuleDraggable  : public juce::Component
{
public:
    ModuleDraggable();
    ~ModuleDraggable() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void mouseDrag (const juce::MouseEvent& event) override;

private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModuleDraggable)
};
