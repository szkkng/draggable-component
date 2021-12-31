/*
  ==============================================================================

    GreyRect.h
    Created: 28 Dec 2021 3:34:25pm
    Author:  Suzuki Kengo

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class GreyRect  : public juce::Component
{
public:
    GreyRect()
    {
        addAndMakeVisible (blueRect);
    };
    
    void paint (juce::Graphics& g) override
    {
        auto grey = juce::Colour::fromFloatRGBA (0.28f, 0.28f, 0.28f, 1.0f);
        g.fillAll (grey.withAlpha (0.1f));
        
        g.setColour (grey);
        g.drawRect (getLocalBounds(), 2);
    }
    
    void resized () override
    {
        blueRect.setBounds (getLocalBounds().withSizeKeepingCentre (40, 40));
    }
    
private:
    struct DraggableComp  : public juce::Component
    {
        juce::ComponentDragger dragger;
        juce::ComponentBoundsConstrainer constrainer;
        
        DraggableComp()
        {
            constrainer.setMinimumOnscreenAmounts (40, 40, 40, 40);
        }

        void paint (juce::Graphics& g) override
        {
            auto bounds = getLocalBounds().reduced (1);
            auto blue = juce::Colour::fromFloatRGBA (0.42f, 0.83f, 1.0f, 1.0f);
            
            g.setColour (blue.withAlpha (0.2f));
            g.fillRect (bounds);

            g.setColour (blue);
            g.drawRect (bounds, 2);
        }

        void mouseDown (const juce::MouseEvent& event) override
        {
            dragger.startDraggingComponent (this, event);
        }

        void mouseDrag (const juce::MouseEvent& event) override
        {
            dragger.dragComponent (this, event, &constrainer);
        }
    };

    DraggableComp blueRect;
};
