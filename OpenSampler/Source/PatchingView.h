/*
  ==============================================================================

    PatchingView.h
    Created: 26 Feb 2021 8:38:48pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Module.h"

using namespace juce;

//==============================================================================

class PatchingView  : public juce::Component
{
public:
    PatchingView();
    ~PatchingView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void addModule(String name, int x, int y);

private:

    std::vector<Module *> modules;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchingView)
};
