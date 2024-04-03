#pragma once

Synthesizer::Synthesizer()
{
    std::cout << "Synthesizer being constructed!" << std::endl;
}

Synthesizer::~Synthesizer()
{
    std::cout << "Synthesizer being deconstructed!" << std::endl;
}

Synthesizer::Keyboard::Keyboard()
{
    hasEightyEightKeys = true;
    midiVelocityEnabled = 127.f;
    numOfBlackKeys = 36;
    synthCompany = "Nord";
    model = "Lead";
    std::cout << "Keyboard is being constructed!" << std::endl;
}

Synthesizer::Keyboard::~Keyboard()
{
    hasEightyEightKeys = true;
    midiVelocityEnabled = 127.f;
    numOfBlackKeys = 36;
    synthCompany = "Nord";
    model = "Lead";
    std::cout << "Keyboard is being deconstructed!" << std::endl;
}

void Synthesizer::Keyboard::pushKey(float midiVelocityPushed, float morePolyphony, bool afterTouched)
{
    midiVelocityEnabled = midiVelocityPushed - morePolyphony - afterTouched;
}

void Synthesizer::Keyboard::releaseKey(float releasedTime, bool usedADSR)
{
    midiVelocityEnabled = releasedTime - usedADSR;
}

int Synthesizer::Keyboard::getNumOfKeysPressed(int numOfMidiEvents)
{
    return numOfMidiEvents;
}

void Synthesizer::Keyboard::changeVelocity(int midiValue)
{
    int velocityValue = 0;
    bool midiTriggered = true;
    int velocityChanged = midiTriggered + velocityValue + midiValue;

    while(midiTriggered)
    {
        ++velocityValue;
        ++velocityChanged;
        std::cout << "New velocity" << std::endl;
        if(velocityChanged >= 1)
            break;
    }
}

void Synthesizer::makeSound(Keyboard keyboard)
{
    keyboard.pushKey(0.5f, 10.f, true);
    std::cout << "Sound was made!" << std::endl;
}

void Synthesizer::showPatchParameters()
{
    numberOfKeys -= 3;
}

float Synthesizer::changeVoltage(float amountOfVoltage, Keyboard keyboard)
{
    return amountOfVoltagePerOctave = amountOfVoltage + keyboard.midiVelocityEnabled;
}

void Synthesizer::changeTimbre(int filterSweep, int rezSweep)
{
    int acidTweak = filterSweep + rezSweep;
    int acid = 0;

    while(acidTweak > acid)
    {
        ++acid;
        std::cout << "Come on you runts, let's have some Aphex acid!" << std::endl;
    }
}

void Synthesizer::printThisValue()
{
    std::cout << "MF Amount of knobs: " << this->numberOfKnobs << std::endl;
}

void Synthesizer::Keyboard::printKeysValue()
{
    std::cout << "MF Amount of Black Keys: " << this->numOfBlackKeys << std::endl;
}
