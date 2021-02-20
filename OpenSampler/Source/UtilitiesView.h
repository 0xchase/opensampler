/*
  ==============================================================================

    SamplerView.h
    Created: 16 Feb 2021 4:16:30pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class UtilitiesView  : public juce::Component
{
public:
    UtilitiesView();
    ~UtilitiesView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UtilitiesView)
};
