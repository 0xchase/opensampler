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
class SamplerView  : public juce::Component
{
public:
    SamplerView();
    ~SamplerView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SamplerView)
};
