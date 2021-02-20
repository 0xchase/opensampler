/*
  ==============================================================================

    BrowserView.h
    Created: 20 Feb 2021 5:03:19pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

//==============================================================================
/*
*/
class BrowserView  : public juce::Component
{
public:
    BrowserView();
    ~BrowserView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    ListBox categoryBox;
    ListBox subCategoryBox;
    ListBox moodBox;
    ListBox authorBox;
    ListBox instrumentBox;    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BrowserView)
};
