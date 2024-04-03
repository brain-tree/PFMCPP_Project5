#pragma once

struct Bank
{
    Bank();
    ~Bank();
    double amountOfMoneyInVault = 987654.56;
    int amountOfArmedGuards = 4;
    int numOfCustomersInLine = 7;
    int numOfTellers = 4;
    float amountOfAccounts = 1355.5f;

    double collectMoney(double amountOfMoneyCollected);
    void serviceClient();
    float wireMoney(float amountOfMoneyWired);
    float convertToCanadianDollar(float dollarValue);
    void thisBankValue();

    JUCE_LEAK_DETECTOR(Bank)
};

struct WrapperBank
{
    WrapperBank(Bank* bankptr) : pointerToBank(bankptr) {}
    ~WrapperBank()
    {
        delete pointerToBank;
    }

    Bank* pointerToBank = nullptr;
};

Bank::Bank()
{
    std::cout << "Bank is being constructed!" << std::endl;
}

Bank::~Bank()
{
    std::cout << "Bank is being deconstructed!" << std::endl;
}

double Bank::collectMoney(double amountOfMoneyCollected)
{
    return amountOfMoneyCollected;
}

void Bank::serviceClient()
{
    std::cout << "Client is being served.\n";
}

float Bank::wireMoney(float amountOfMoneyWired)
{
    return amountOfMoneyWired;
}

float Bank::convertToCanadianDollar(float dollarValue)
{
    float usdValue = 1.f;
    float exchangeRate = 0.74f;
    float convertedValue = usdValue / exchangeRate;
    float totalCash = 1452584.63f;
    float markupRate = convertedValue * 100.f;
    float conversionValue = totalCash * convertedValue + markupRate;
    bool totalConverted = true;

    while(dollarValue <= 1)
    {
        ++conversionValue;
        std::cout << "Calculated conversion value: " << conversionValue << std::endl;
        if(totalConverted)
            break;
    }
    return conversionValue;
}

void Bank::thisBankValue()
{
    std::cout << "MF How many guards do we have? " << this->amountOfArmedGuards << std::endl;
}
