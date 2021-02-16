/*
  ==============================================================================

    MainView.h
    Created: 13 Feb 2021 1:20:58pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MainView  : public juce::Component,
                    private juce::MidiInputCallback,
                    private juce::MidiKeyboardStateListener
{
public:
    MainView();
    ~MainView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::AudioDeviceManager deviceManager;           // [1]
    juce::ComboBox midiInputList;                     // [2]
    juce::Label midiInputListLabel;
    int lastInputIndex = 0;                           // [3]
    bool isAddingFromMidiInput = false;               // [4]
    
    juce::MidiKeyboardState keyboardState;            // [5]
    juce::MidiKeyboardComponent keyboardComponent;    // [6]
    
    juce::TextEditor midiMessagesBox;
    double startTime;
    
    void handleIncomingMidiMessage (juce::MidiInput* source, const juce::MidiMessage& message) override
    {
        const juce::ScopedValueSetter<bool> scopedInputFlag (isAddingFromMidiInput, true);
        keyboardState.processNextMidiEvent (message);
        //postMessageToList (message, source->getName());
    }
    
    void handleNoteOn (juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
    {
        if (! isAddingFromMidiInput)
        {
            auto m = juce::MidiMessage::noteOn (midiChannel, midiNoteNumber, velocity);
            m.setTimeStamp (juce::Time::getMillisecondCounterHiRes() * 0.001);
            //postMessageToList (m, "On-Screen Keyboard");
        }
    }
    
    void handleNoteOff (juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/) override
    {
        if (! isAddingFromMidiInput)
        {
            auto m = juce::MidiMessage::noteOff (midiChannel, midiNoteNumber);
            m.setTimeStamp (juce::Time::getMillisecondCounterHiRes() * 0.001);
            //postMessageToList (m, "On-Screen Keyboard");
        }
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainView)
};
