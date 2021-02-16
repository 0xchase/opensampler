/*
  ==============================================================================

    ModularView.h
    Created: 16 Feb 2021 4:17:09pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ModularView  : public juce::Component
{
public:
    ModularView();
    ~ModularView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModularView)
};
