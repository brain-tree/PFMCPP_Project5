#pragma once

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

struct WrapperEffectsRack
{
    WrapperEffectsRack(EffectsRack* fxptr) : pointerToEffectsRack(fxptr) {}
    ~WrapperEffectsRack()
    {
        delete pointerToEffectsRack;
    }

    EffectsRack* pointerToEffectsRack = nullptr;
};

EffectsRack::EffectsRack()
{
    std::cout << "EffectsRack is being constructed" << std::endl;
}

EffectsRack::~EffectsRack()
{
    std::cout << "EffectsRack is being deconstructed" << std::endl;
}

void EffectsRack::cueAnEffect(int p1, int p2, float p3)
{
    subModule.showPatchParameters();
    randomEffect.changeTimbre(p1, p2);
    weightedKeys.pushKey(p3);

    std::cout << "Effect rack is active" << std::endl;
}

void EffectsRack::chooseAnEffect(int olympicMenuDive)
{
    EffectsRack effectsRack;
    effectsRack.subModule.numberOfOscillators = 3;
    weightedKeys.changeVelocity(olympicMenuDive);
    effectsRack.randomEffect.numberOfKnobs = 15;
}

void EffectsRack::printRackValue()
{
    std::cout << "MF Amount of audio effects processors: " << this->amountOfEffects << std::endl;
}
