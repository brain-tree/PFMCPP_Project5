#pragma once
#include "LeakedObjectDetector.h"

struct Bank
{
    Bank();
    ~Bank();
    double amountOfMoneyInVault = 987654.56;
    int amountOfArmedGuards = 4;
    int numOfCustomersInLine = 7;
    int numOfTellers = 4;
    float amountOfAccounts = 1355.5f;

    double collectMoney(const double& amountOfMoneyCollected);
    void serviceClient() const;
    float wireMoney(const float& amountOfMoneyWired);
    float convertToCanadianDollar(float dollarValue);
    void thisBankValue() const;

    JUCE_LEAK_DETECTOR(Bank)
};
