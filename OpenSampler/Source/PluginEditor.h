/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "BrowserView.h"
#include "MainView.h"
#include "ModularView.h"
#include "UtilitiesView.h"

#include "TopBar.h"
#include "BottomBar.h"

using namespace juce;

//==============================================================================
/**
*/

class OpenSamplerAudioProcessorEditor  :   public juce::AudioProcessorEditor,
                                            public juce::FileDragAndDropTarget,
                                            public juce::Button::Listener
{
public:
    OpenSamplerAudioProcessorEditor (OpenSamplerAudioProcessor&);
    ~OpenSamplerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    bool isInterestedInFileDrag (const juce::StringArray &files) override;
    void filesDropped (const juce::StringArray& files, int x, int y) override;
    
    void createButton(int x, int y, int width, int height);
    
    void buttonClicked (juce::Button* button) override;

private:
    juce::TextButton mLoadButton { "Load a sample (temporary)" };
    
    juce::TextButton makeKnob { "Make a knob (temporary)" };
    
    std::vector<juce::TextButton *> buttons;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OpenSamplerAudioProcessor& audioProcessor;
    
    //==============================================================================
    
    BrowserView browserView;
    MainView mainView;
    ModularView modularView;
    UtilitiesView utilitiesView;
    
    BottomBar bottomBar;
    TopBar topBar;
    
    void tabClicked(Button* buttonThatWasClicked);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OpenSamplerAudioProcessorEditor)
};
