/*
  ==============================================================================

    ModularView.h
    Created: 16 Feb 2021 4:17:09pm
    Author:  Chase Kanipe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "Module.h"
#include "PatchingView.h"
#include "ModulesListView.h"

//==============================================================================
/*
*/
class ModularView  : public juce::Component, public juce::DragAndDropContainer, public juce::DragAndDropTarget
{
public:
    ModularView();
    ~ModularView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    ModuleDraggable testModule;
    
    
    virtual bool isInterestedInDragSource (const SourceDetails& dragSourceDetails) override {
        return true;
    }
    
    virtual void itemDragEnter (const SourceDetails&) override
    {
        //std::cout << "DragAndDropCarrier():: itemDragEnter()" << std::endl;
        repaint();
    }
    
    virtual void itemDragMove (const SourceDetails&) override
    {
        //std::cout << "DragAndDropCarrier():: itemDragMove()" << std::endl;
    }
    
    virtual void itemDragExit (const SourceDetails&) override
    {
        //std::cout << "DragAndDropCarrier():: itemDragExit()" << std::endl;
        repaint();
    }
    
    virtual void itemDropped (const SourceDetails& dragSourceDetails) override {
        if (dragSourceDetails.localPosition.getX() > patchingView.getX() &&
            dragSourceDetails.localPosition.getX() < patchingView.getX()+patchingView.getWidth() &&
            dragSourceDetails.localPosition.getY() > patchingView.getY() &&
            dragSourceDetails.localPosition.getY() < patchingView.getY()+patchingView.getHeight()
            ) {
            
            puts("Dropped");
            
            auto mouseX = 0;
            auto mouseY = 0;
            
            patchingView.addModule(dragSourceDetails.description, dragSourceDetails.localPosition.getX() + mouseX, dragSourceDetails.localPosition.getY() + mouseY);
            
        } else {
            puts("Didn't drop");
        }
    }
    
private:
    
    PatchingView patchingView;
    ModulesListView modulesListView;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModularView)
};
