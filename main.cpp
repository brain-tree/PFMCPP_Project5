/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/


/*
 copied UDT 1:
 */
#include <iostream>

struct Synthesizer
{
    Synthesizer();
    ~Synthesizer();
    int numberOfOscillators = 3;
    int numberofKnobs = 15;
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
    };

    void makeSound(Keyboard keyboard);
    void showPatchParameters();
    float changeVoltage(float amountOfVoltage, Keyboard keyboard);
    void changeTimbre(int filterSweep, int rezSweep);

    Keyboard eventsOnSynth;
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
    };

    void makeFood(Kitchen kitchen);
    void serveDiners(Kitchen kitchen);
    float chargeMoney(float moneyOfMeal);
    void cleanTheKitchen(int amountOfAmmonia, int numOfSponges);

    Kitchen patronsBeingServed;
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

    void cueAnEffect(int parameter1, int parameter2, float parameter3);
    void chooseAnEffect(int menuDive);
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
    effectsRack.randomEffect.numberofKnobs = 15;
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

    void seatACustomer();
    void counterSeating(float stools);
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
    Synthesizer instantiatedSynthesizer;
    instantiatedSynthesizer.makeSound(instantiatedSynthesizer.eventsOnSynth);
    instantiatedSynthesizer.showPatchParameters();
    instantiatedSynthesizer.changeVoltage(55.5, instantiatedSynthesizer.eventsOnSynth);
    instantiatedSynthesizer.changeTimbre(0, 1);

    Synthesizer::Keyboard boardWithKeys;
    boardWithKeys.pushKey(127.f, 10.f, true);
    boardWithKeys.releaseKey(200.f, true);
    boardWithKeys.getNumOfKeysPressed(127);
    boardWithKeys.changeVelocity(127);

    Restaurant placeToEat;
    placeToEat.makeFood(placeToEat.patronsBeingServed);
    placeToEat.serveDiners(placeToEat.patronsBeingServed);
    placeToEat.chargeMoney(20);
    placeToEat.cleanTheKitchen(0, 0);

    Restaurant::Kitchen cookArea;
    cookArea.fillFryerWithOil(50.75, 2.0, false);
    cookArea.printOrderTicket(5, false);
    cookArea.annualRevenue(359000.52);
    cookArea.replaceTheOven(2, 1);

    Bank localBank;
    localBank.serviceClient();
    localBank.collectMoney(258.22);
    localBank.wireMoney(300.f);
    localBank.convertToCanadianDollar(1.f);

    EffectsRack outboardFX;
    outboardFX.cueAnEffect(0, 0, 0);
    outboardFX.chooseAnEffect(0);

    DiningRoom roomForEating;
    roomForEating.seatACustomer();
    roomForEating.counterSeating(1);
    
    std::cout << "good to go!" << std::endl;
}
