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

private:
    
    int buttonSize = 30;
    int buttonPadding = 10;
    
    ImageButton presetViewButton;
    ImageButton mainViewButton;
    ImageButton midiEffectsViewButton;
    ImageButton samplerViewButton;
    ImageButton audioEffectsViewButton;
    
    void initPresetView() {
        presetViewButton.setButtonText("Preset View");
        
        Image normalButton = ImageCache::getFromMemory (BinaryData::list_png, BinaryData::list_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::list_png, BinaryData::list_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::list_png, BinaryData::list_pngSize);
        
        presetViewButton.setImages(false, true, true, normalButton, 0.5000f, Colour (0x00000000), overButton, 0.500f, Colour (0x00000000), downButton, 1.000f, Colour (0x00000000));
        presetViewButton.setColour (0.5f, Colours::red.withAlpha (0.5f));
        presetViewButton.setBounds(getWidth()/6, buttonPadding, buttonSize, buttonSize);
        addAndMakeVisible(presetViewButton);
    }
    
    void initMainView() {
        mainViewButton.setButtonText("Main View");
        
        Image normalButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        
        mainViewButton.setImages(false, true, true, normalButton, 0.5000f, Colour (0x00000000), overButton, 0.500f, Colour (0x00000000), downButton, 1.000f, Colour (0x00000000));
        mainViewButton.setColour (0.5f, Colours::red.withAlpha (0.5f));
        mainViewButton.setBounds(getWidth()/6*2, buttonPadding, buttonSize, buttonSize);
        addAndMakeVisible(mainViewButton);
    }
    
    void initMidiEffectsView() {
        midiEffectsViewButton.setButtonText("MIDI Effects");
        
        Image normalButton = ImageCache::getFromMemory (BinaryData::midi_png, BinaryData::midi_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::midi_png, BinaryData::midi_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::midi_png, BinaryData::midi_pngSize);
        
        midiEffectsViewButton.setImages(false, true, true, normalButton, 0.5000f, Colour (0x00000000), overButton, 0.500f, Colour (0x00000000), downButton, 1.000f, Colour (0x00000000));
        midiEffectsViewButton.setColour (0.5f, Colours::red.withAlpha (0.5f));
        midiEffectsViewButton.setBounds(getWidth()/6*3, buttonPadding, buttonSize, buttonSize);
        addAndMakeVisible(midiEffectsViewButton);
    }
    
    void initSamplerView() {
        samplerViewButton.setButtonText("Sampler");
        
        Image normalButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::piano_png, BinaryData::piano_pngSize);
        
        samplerViewButton.setImages(false, true, true, normalButton, 0.5000f, Colour (0x00000000), overButton, 0.500f, Colour (0x00000000), downButton, 1.000f, Colour (0x00000000));
        samplerViewButton.setColour (0.5f, Colours::red.withAlpha (0.5f));
        samplerViewButton.setBounds(getWidth()/6*4, buttonPadding, buttonSize, buttonSize);
        addAndMakeVisible(samplerViewButton);
    }
    
    void initAudioEffectsView() {
        audioEffectsViewButton.setButtonText("Sampler");
        
        Image normalButton = ImageCache::getFromMemory (BinaryData::waveform_png, BinaryData::waveform_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::waveform_png, BinaryData::waveform_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::waveform_png, BinaryData::waveform_pngSize);
        
        audioEffectsViewButton.setImages(false, true, true, normalButton, 0.5000f, Colour (0x00000000), overButton, 0.500f, Colour (0x00000000), downButton, 1.000f, Colour (0x00000000));
        audioEffectsViewButton.setColour (0.5f, Colours::red.withAlpha (0.5f));
        audioEffectsViewButton.setBounds(getWidth()/6*5, buttonPadding, buttonSize, buttonSize);
        addAndMakeVisible(audioEffectsViewButton);
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BottomBar)
};
