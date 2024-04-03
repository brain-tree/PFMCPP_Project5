#pragma once

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
