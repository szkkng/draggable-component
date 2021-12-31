#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    addAndMakeVisible (greyRect);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    auto black = juce::Colour::fromFloatRGBA (0.08f, 0.08f, 0.08f, 1.0f);
    g.fillAll (black);
}

void MainComponent::resized()
{
    greyRect.setBounds (getLocalBounds().withSizeKeepingCentre (400, 250));
}
