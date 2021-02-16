/*
  ==============================================================================

    TopBar.h
    Created: 13 Feb 2021 2:02:34pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;


//==============================================================================
/*
*/
class TopBar  : public juce::Component
{
public:
    TopBar();
    ~TopBar() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    ImageButton instrumentManagerViewButton;
    ImageButton instrumentBrowserViewButton;
    ImageButton scriptEditorViewButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TopBar)
};
