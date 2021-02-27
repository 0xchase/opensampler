/*
  ==============================================================================

    ModulesListView.h
    Created: 26 Feb 2021 8:39:58pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ModuleDraggable.h"

//==============================================================================
/*
*/
class ModulesListView  : public juce::Component
{
public:
    ModulesListView();
    ~ModulesListView() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    ModuleDraggable testModule;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModulesListView)
};
