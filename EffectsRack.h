#pragma once
#include "LeakedObjectDetector.h"
#include "Synthesizer.h"

struct EffectsRack
{
    EffectsRack();
    ~EffectsRack();
    Synthesizer subModule;
    Synthesizer randomEffect;
    Synthesizer::Keyboard weightedKeys;
    int amountOfEffects = 10;

    void cueAnEffect(int parameter1, int parameter2, float parameter3);
    void chooseAnEffect(int menuDive);
    void printRackValue();

    JUCE_LEAK_DETECTOR(EffectsRack)
};
