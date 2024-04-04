#pragma once
#include "LeakedObjectDetector.h"

struct Synthesizer
{
    Synthesizer();
    ~Synthesizer();
    int numberOfOscillators = 3;
    int numberOfKnobs = 15;
    float amountOfVoltagePerOctave = 0.5f;
    int numberOfKeys = 88;
    int numberOfDigitalDisplays = 1;

    struct Keyboard
    {
        Keyboard();
        ~Keyboard();
        bool hasEightyEightKeys;
        float midiVelocityEnabled;
        int numOfBlackKeys;
        std::string synthCompany;
        std::string model;

        void pushKey(float midiVelocity, float polyphony = 10.f, bool afterTouch = true);
        void releaseKey(float releaseTime, bool usesADSR = true);
        int getNumOfKeysPressed(int numOfMidiEvents);
        void changeVelocity(int midiValue);
        void printKeysValue();

        JUCE_LEAK_DETECTOR(Keyboard)
    };

    void makeSound(Keyboard keyboard);
    void showPatchParameters();
    float changeVoltage(float amountOfVoltage, Keyboard keyboard);
    void changeTimbre(int filterSweep, int rezSweep);
    void printThisValue();

    Keyboard eventsOnSynth;

    JUCE_LEAK_DETECTOR(Synthesizer)
};
