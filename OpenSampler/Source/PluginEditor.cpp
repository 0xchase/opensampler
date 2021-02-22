/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;

//==============================================================================
OpenSamplerAudioProcessorEditor::OpenSamplerAudioProcessorEditor (OpenSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p),
        audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    mLoadButton.onClick = [&]() { audioProcessor.loadFile(); };
    mLoadButton.setBounds(browserView.getWidth()/2-100, browserView.getHeight()/2-100, 200, 200);
    browserView.addAndMakeVisible(mLoadButton);
    
    setSize (1200, 800); // Plugin window size
    
    makeKnob.onClick = [&]() {};
    makeKnob.setBounds(browserView.getWidth()/2, browserView.getHeight()/2, 100, 100);
    mainView.addAndMakeVisible(makeKnob);
    
    browserView.setBounds(5, 70, 1190, 665);
    addAndMakeVisible(browserView);
    browserView.setVisible(false);
    
    mainView.setBounds(5, 70, 1190, 665);
    addAndMakeVisible(mainView);
    mainView.setVisible(true);
    
    modularView.setBounds(5, 70, 1190, 665);
    addAndMakeVisible(modularView);
    modularView.setVisible(false);
    
    utilitiesView.setBounds(5, 70, 1190, 665);
    addAndMakeVisible(utilitiesView);
    utilitiesView.setVisible(false);
    
    topBar.setBounds(5, 5, 1190, 60);
    addAndMakeVisible(topBar);
    
    bottomBar.setBounds(5, 740, 1190, 55);
    addAndMakeVisible(bottomBar);
    
    bottomBar.browserViewButton.addListener(this);
    bottomBar.mainViewButton.addListener(this);
    bottomBar.modularViewButton.addListener(this);
    bottomBar.utilitiesViewButton.addListener(this);
    
}

void OpenSamplerAudioProcessorEditor::buttonClicked (juce::Button* button)
{
    browserView.setVisible(false);
    mainView.setVisible(false);
    modularView.setVisible(false);
    utilitiesView.setVisible(false);
    
    if (button == &bottomBar.browserViewButton) {
        browserView.setVisible(true);
    } else if (button == &bottomBar.mainViewButton) {
        mainView.setVisible(true);
    } else if (button == &bottomBar.modularViewButton) {
        modularView.setVisible(true);
    } else if (button == &bottomBar.utilitiesViewButton) {
        utilitiesView.setVisible(true);
    }
}

void OpenSamplerAudioProcessorEditor::tabClicked(Button* buttonThatWasClicked)
{
    
}

void OpenSamplerAudioProcessorEditor::createButton(int x, int y, int width, int height) {
    
    auto button = new juce::TextButton();
    button->setButtonText("Text here");
    button->setBounds(x, y, width, height);

    //button->setImages(false, false, true, normalButton, 1.0f, {}, overButton, 1.0f, {}, downButton, 1.0f, {});
    addAndMakeVisible(button);
    buttons.push_back(button);
    
}

OpenSamplerAudioProcessorEditor::~OpenSamplerAudioProcessorEditor()
{
}

//==============================================================================
void OpenSamplerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
    g.fillAll(juce::Colour::fromRGB(26, 26, 26));
    
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    
    /*
    if (audioProcessor.getNumSamplerSounds() > 0)
    {
        g.fillAll(juce::Colours::red);

        g.drawText("Sound Loaded", getWidth() / 2 - 50, getHeight() / 2 - 10, 100, 20, juce::Justification::centred);
    } else {
                g.drawText("Load a sound", getWidth() / 2 - 50, getHeight() / 2 - 10, 100, 20, juce::Justification::centred);
    }
     */
    
    /*
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
     */
}

void OpenSamplerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mLoadButton.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 50, 100, 100);
    
}

bool OpenSamplerAudioProcessorEditor::isInterestedInFileDrag(const juce::StringArray& files)
{
    for (auto file: files) {
        if (file.contains(".wav") || files.contains(".mp3") || file.contains(".aif")) {
            return true;
        }
    }
    return false;
}

void OpenSamplerAudioProcessorEditor::filesDropped(const juce::StringArray& files, int x, int y)
{
    for (auto file: files) {
        if (isInterestedInFileDrag(files)) {
            audioProcessor.loadFile(file);
        }
    }
    repaint();
}
