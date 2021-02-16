/*
  ==============================================================================

    BottomBar.h
    Created: 13 Feb 2021 2:02:56pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

//==============================================================================
/*
*/
class BottomBar  : public juce::Component
{
public:
    BottomBar();
    ~BottomBar() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void addTab();
    
    ImageButton mainViewButton;
    ImageButton modularViewButton;
    ImageButton samplerViewButton;
    
private:
    
    int buttonHeight = 25;
    int buttonWidth = 60;
    int buttonPadding = 13;
    
    void initMainViewButton() {
        mainViewButton.setButtonText("Main");
        
        Image normalButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        
        mainViewButton.setImages(false, true, true, normalButton, 0.5000f, Colour (0x00000000), overButton, 0.500f, Colour (0x00000000), downButton, 1.000f, Colour (0x00000000));
        mainViewButton.setColour (0.5f, Colours::red.withAlpha (0.5f));
        mainViewButton.setBounds(getWidth()/4*1, buttonPadding, buttonWidth, buttonHeight);
        addAndMakeVisible(mainViewButton);
    }
    
    void initModularViewButton() {
        modularViewButton.setButtonText("Modular");
        
        Image normalButton = ImageCache::getFromMemory (BinaryData::gate_png, BinaryData::gate_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::gate_png, BinaryData::gate_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::gate_png, BinaryData::gate_pngSize);
        
        modularViewButton.setImages(false, true, true, normalButton, 0.5000f, Colour (0x00000000), overButton, 0.500f, Colour (0x00000000), downButton, 1.000f, Colour (0x00000000));
        modularViewButton.setColour (0.5f, Colours::red.withAlpha (0.5f));
        modularViewButton.setBounds(getWidth()/4*2, buttonPadding, buttonWidth, buttonHeight);
        addAndMakeVisible(modularViewButton);
    }
    
    void initSamplerViewButton() {
        samplerViewButton.setButtonText("Sampler");
        
        Image normalButton = ImageCache::getFromMemory (BinaryData::waveform_png, BinaryData::waveform_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::waveform_png, BinaryData::waveform_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::waveform_png, BinaryData::waveform_pngSize);
        
        samplerViewButton.setImages(false, true, true, normalButton, 0.5000f, Colour (0x00000000), overButton, 0.500f, Colour (0x00000000), downButton, 1.000f, Colour (0x00000000));
        samplerViewButton.setColour (0.5f, Colours::red.withAlpha (0.5f));
        samplerViewButton.setBounds(getWidth()/4*3, buttonPadding, buttonWidth, buttonHeight);
        addAndMakeVisible(samplerViewButton);
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BottomBar)
};
