/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */







/*
 copied UDT 1:
 */
#include <iostream>
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

struct WrapperSynthesizer
{
    WrapperSynthesizer(Synthesizer* synthptr) : pointerToSynthesizer(synthptr) {}
    ~WrapperSynthesizer()
    {
        delete pointerToSynthesizer;
    }

    Synthesizer* pointerToSynthesizer = nullptr;
};

struct WrapperKeyboard
{
    WrapperKeyboard(Synthesizer::Keyboard* keysptr) : pointerToKeyboard(keysptr) {}
    ~WrapperKeyboard()
    {
        delete pointerToKeyboard;
    }

    Synthesizer::Keyboard* pointerToKeyboard = nullptr;
};

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
/*
 copied UDT 2:
 */
struct Restaurant
{
    Restaurant();
    ~Restaurant();
    int amountOfMenuItems;
    std::string nameOfIngredientsPerMenuItem;
    int numberOfOvens;
    int numberOfEmployees;
    int numberOfTables;

    struct Kitchen
    {
        Kitchen();
        ~Kitchen();
        int numOfCooks;
        int numOfDeepFryers;
        bool greaseCollected;
        float gallonsOfVegOil;
        std::string orderName;
        double totalAmountOfOil;

        void fillFryerWithOil(double amountOfOil, double costOfVegOilPerGallon = 2.0, bool oilNeedsReplaced = false);
        void printOrderTicket(int orderNumber, bool hasSpecialInstructions = false);
        double annualRevenue(double annualProfit);
        void replaceTheOven(int newOven, int oldOven);
        void printKitchenValue();

        JUCE_LEAK_DETECTOR(Kitchen)
    };

    void makeFood(Kitchen kitchen);
    void serveDiners(Kitchen kitchen);
    float chargeMoney(float moneyOfMeal);
    void cleanTheKitchen(int amountOfAmmonia, int numOfSponges);
    void printRestValue();

    Kitchen patronsBeingServed;

    JUCE_LEAK_DETECTOR(Restaurant)
};

struct WrapperRestaurant
{
    WrapperRestaurant(Restaurant* restptr) : pointerToRestaurant(restptr) {}
    ~WrapperRestaurant()
    {
        delete pointerToRestaurant;
    }

    Restaurant* pointerToRestaurant = nullptr;
};

struct WrapperKitchen
{
    WrapperKitchen(Restaurant::Kitchen* kitptr) : pointerToKitchen(kitptr) {}
    ~WrapperKitchen()
    {
        delete pointerToKitchen;
    }

    Restaurant::Kitchen* pointerToKitchen = nullptr;
};

Restaurant::Restaurant()
{
    amountOfMenuItems = 90;
    nameOfIngredientsPerMenuItem = "Tomatoes, lettuce, cheese, meat, and mayo";
    numberOfOvens = 4;
    numberOfEmployees = 10;
    numberOfTables = 30;
    std::cout << "Restaurant being constructed!" << std::endl;
}

Restaurant::~Restaurant()
{
    amountOfMenuItems = 90;
    nameOfIngredientsPerMenuItem = "Tomatoes, lettuce, cheese, meat, and mayo";
    numberOfOvens = 4;
    numberOfEmployees = 10;
    numberOfTables = 30;
    std::cout << "Restaurant being deconstructed!" << std::endl;
}

Restaurant::Kitchen::Kitchen() : numOfCooks(3), numOfDeepFryers(2), greaseCollected(true), gallonsOfVegOil(20.f), orderName("Lisa"), totalAmountOfOil(100.00)
{
    std::cout << "Kitchen being constructed!" << std::endl;
}

Restaurant::Kitchen::~Kitchen()
{
    std::cout << "Kitchen being deconstructed!" << std::endl;
}

void Restaurant::Kitchen::fillFryerWithOil(double amountOfOil, double costOfVegOilPerGallon, bool oilNeedsReplaced)
{
    totalAmountOfOil = amountOfOil - costOfVegOilPerGallon - oilNeedsReplaced;
}

void Restaurant::Kitchen::printOrderTicket(int orderNumber, bool hasSpecialInstructions)
{
    numOfCooks = orderNumber + hasSpecialInstructions;
}

double Restaurant::Kitchen::annualRevenue(double annualProfit)
{
    std::cout << "Displaying annual profit" << std::endl;
    return annualProfit;
}

void Restaurant::Kitchen::replaceTheOven(int newPizzaOven, int oldPizzaOven)
{
    int numOfNewOvens = 2;
    int numOfOldOvens = 1;
    int sizeOfNewOven = oldPizzaOven * 2;
    int amountOfPizzasPerHour = sizeOfNewOven * newPizzaOven + oldPizzaOven - numOfOldOvens;

    while(numOfNewOvens > 2)
    {
        ++amountOfPizzasPerHour;
        std::cout << "More pizzas capable" << std::endl;
    }
}

void Restaurant::makeFood(Kitchen kitchen)
{
    amountOfMenuItems = kitchen.numOfCooks + kitchen.numOfDeepFryers;
}

void Restaurant::serveDiners(Kitchen kitchen)
{
    numberOfEmployees = kitchen.numOfCooks + kitchen.numOfDeepFryers;
}

float Restaurant::chargeMoney(float moneyOfMeal)
{
    return moneyOfMeal;
}

void Restaurant::cleanTheKitchen(int amountOfAmmonia, int numOfSponges)
{
    bool kitchenIsClean = true;
    int sponges = 0;
    int ammonia = 0;
    int cleanTheKitchen = amountOfAmmonia + numOfSponges;

    while(sponges && ammonia <= 1)
    {
        ++sponges;
        ++ammonia;
        ++cleanTheKitchen;
        std::cout << "The kitchen is being cleaned!" << std::endl;
        if(kitchenIsClean)
            break;
    }
}

void Restaurant::printRestValue()
{
    std::cout << "MF Amount of menu items: " << this->amountOfMenuItems << std::endl;
}

void Restaurant::Kitchen::printKitchenValue()
{
    std::cout << "MF Order name: " << this->orderName << std::endl;
}
/*
 copied UDT 3:
 */
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
/*
 new UDT 4:
 with 2 member functions
 */
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
/*
 new UDT 5:
 with 2 member functions
 */
struct DiningRoom
{
    DiningRoom();
    ~DiningRoom();
    Restaurant table;
    Restaurant counter;
    Restaurant::Kitchen foyer;
    int amountOfSeatedCustomers = 20;

    void seatACustomer();
    void counterSeating(float stools);
    void printCustomersSeated();

    JUCE_LEAK_DETECTOR(DiningRoom)
};

struct WrapperDiningRoom
{
    WrapperDiningRoom(DiningRoom* drptr) : pointerToDiningRoom(drptr) {}
    ~WrapperDiningRoom()
    {
        delete pointerToDiningRoom;
    }

    DiningRoom* pointerToDiningRoom = nullptr;
};

DiningRoom::DiningRoom()
{
    std::cout << "Dining Room is being constructed" << std::endl;
}

DiningRoom::~DiningRoom()
{
    std::cout << "Dining Room is being deconstructed" << std::endl;
}

void DiningRoom::seatACustomer()
{
    table.amountOfMenuItems = 100;
    counter.numberOfEmployees = 2;
    foyer.orderName = "Reggie";
}

void DiningRoom::counterSeating(float whichStool)
{
    table.nameOfIngredientsPerMenuItem = 50;
    counter.chargeMoney(whichStool);
    foyer.gallonsOfVegOil = 10;
}

void DiningRoom::printCustomersSeated()
{
    std::cout << "MF How many customers have been seated? " << this->amountOfSeatedCustomers << std::endl;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    WrapperSynthesizer wrapperSynth(new Synthesizer());
    wrapperSynth.pointerToSynthesizer->makeSound(wrapperSynth.pointerToSynthesizer->eventsOnSynth);
    wrapperSynth.pointerToSynthesizer->showPatchParameters();
    wrapperSynth.pointerToSynthesizer->changeVoltage(55.5, wrapperSynth.pointerToSynthesizer->eventsOnSynth);
    wrapperSynth.pointerToSynthesizer->changeTimbre(0, 1);
    wrapperSynth.pointerToSynthesizer->printThisValue();

    std::cout << "main() Amount of knobs: " << wrapperSynth.pointerToSynthesizer->numberOfKnobs << std::endl;

    Synthesizer::Keyboard boardWithKeys;
    WrapperKeyboard wapperKeys(new Synthesizer::Keyboard());
    wapperKeys.pointerToKeyboard->pushKey(127.f, 10.f, true);
    wapperKeys.pointerToKeyboard->releaseKey(200.f, true);
    wapperKeys.pointerToKeyboard->getNumOfKeysPressed(127);
    wapperKeys.pointerToKeyboard->changeVelocity(127);
    wapperKeys.pointerToKeyboard->printKeysValue();

    std::cout << "main() Amount of Black Keys: " << boardWithKeys.numOfBlackKeys << std::endl;

    WrapperRestaurant wrapperRest(new Restaurant());
    wrapperRest.pointerToRestaurant->makeFood(wrapperRest.pointerToRestaurant->patronsBeingServed);
    wrapperRest.pointerToRestaurant->serveDiners(wrapperRest.pointerToRestaurant->patronsBeingServed);
    wrapperRest.pointerToRestaurant->chargeMoney(20);
    wrapperRest.pointerToRestaurant->cleanTheKitchen(0, 0);
    wrapperRest.pointerToRestaurant->printRestValue();

    std::cout << "main() Amount of menu items: " << wrapperRest.pointerToRestaurant->amountOfMenuItems << std::endl;

    WrapperKitchen wrapperKit(new Restaurant::Kitchen());
    wrapperKit.pointerToKitchen->fillFryerWithOil(50.75, 2.0, false);
    wrapperKit.pointerToKitchen->printOrderTicket(5, false);
    wrapperKit.pointerToKitchen->annualRevenue(359000.52);
    wrapperKit.pointerToKitchen->replaceTheOven(2, 1);
    wrapperKit.pointerToKitchen->printKitchenValue();

    std::cout << "main() Order name: " << wrapperKit.pointerToKitchen->orderName << std::endl;

//    Bank localBank;
    WrapperBank wrapperBank(new Bank());
    wrapperBank.pointerToBank->serviceClient();
    wrapperBank.pointerToBank->collectMoney(258.22);
    wrapperBank.pointerToBank->wireMoney(300.f);
    wrapperBank.pointerToBank->convertToCanadianDollar(1.f);
    wrapperBank.pointerToBank->thisBankValue();

    std::cout << "main() How many guards do we have? " << wrapperBank.pointerToBank->amountOfArmedGuards << std::endl;

    EffectsRack outboardFX;
    WrapperEffectsRack wrapperFX(new EffectsRack());
    wrapperFX.pointerToEffectsRack->cueAnEffect(0, 0, 0);
    wrapperFX.pointerToEffectsRack->chooseAnEffect(0);
    wrapperFX.pointerToEffectsRack->printRackValue();

    std::cout << "main() Amount of audio effects processors: " << wrapperFX.pointerToEffectsRack->amountOfEffects << std::endl;

    WrapperDiningRoom wrapperDiningRoom(new DiningRoom());
    wrapperDiningRoom.pointerToDiningRoom->seatACustomer();
    wrapperDiningRoom.pointerToDiningRoom->counterSeating(1);
    wrapperDiningRoom.pointerToDiningRoom->printCustomersSeated();

    std::cout << "main() How many customers have been seated? " << wrapperDiningRoom.pointerToDiningRoom->amountOfSeatedCustomers << std::endl;

    std::cout << "good to go!" << std::endl;
}
