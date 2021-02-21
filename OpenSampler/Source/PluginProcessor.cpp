/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OpenSamplerAudioProcessor::OpenSamplerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    mFormatManager.registerBasicFormats();
    
    for (int i = 0; i < mNumVoices; i++) {
        mSampler.addVoice(new juce::SamplerVoice());
    }
}

OpenSamplerAudioProcessor::~OpenSamplerAudioProcessor()
{
    mFormatReader = nullptr;
}

//==============================================================================
const juce::String OpenSamplerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OpenSamplerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OpenSamplerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool OpenSamplerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double OpenSamplerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OpenSamplerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OpenSamplerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OpenSamplerAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String OpenSamplerAudioProcessor::getProgramName (int index)
{
    return {};
}

void OpenSamplerAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void OpenSamplerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    mSampler.setCurrentPlaybackSampleRate(sampleRate);
}

void OpenSamplerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OpenSamplerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void OpenSamplerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    mSampler.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool OpenSamplerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* OpenSamplerAudioProcessor::createEditor()
{
    return new OpenSamplerAudioProcessorEditor (*this);
}

//==============================================================================
void OpenSamplerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OpenSamplerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void OpenSamplerAudioProcessor::loadFile()
{
    mSampler.clearSounds();
    
    juce::FileChooser chooser { "Please load a file" };
    if (chooser.browseForFileToOpen()) {
        auto file = chooser.getResult();
        mFormatReader = mFormatManager.createReaderFor(file);
        
        juce::BigInteger range;
        range.setRange(0, 128, true);
        
        mSampler.addSound(new juce::SamplerSound ("Sample", *mFormatReader, range, 60, 0.1, 0.1, 10));
    }
}

void OpenSamplerAudioProcessor::loadFile(const juce::String& path)
{
    //mSampler.clearSounds();
    
    FileChooser chooser { "Please load a file" };
    /*
    if (false && chooser.browseForFileToOpen()) {
        File file = chooser.getResult();
        mFormatReader = mFormatManager.createReaderFor(file);
        
        BigInteger range;
        range.setRange(0, 128, true);
        
        mSampler.addSound(new SamplerSound("Sample", *mFormatReader, range, 60, 0.1, 0.1, 10.0));
    }
     */
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OpenSamplerAudioProcessor();
}
