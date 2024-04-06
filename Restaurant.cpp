#include "Restaurant.h"

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

double Restaurant::Kitchen::annualRevenue(const double& annualProfit)
{
    std::cout << "Displaying annual profit" << std::endl;
    return annualProfit;
}

void Restaurant::Kitchen::replaceTheOven(int newPizzaOven, int oldPizzaOven) const
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

float Restaurant::chargeMoney(const float& moneyOfMeal)
{
    return moneyOfMeal;
}

void Restaurant::cleanTheKitchen(const int& amountOfAmmonia, const int& numOfSponges)
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

void Restaurant::printRestValue() const
{
    std::cout << "MF Amount of menu items: " << this->amountOfMenuItems << std::endl;
}

void Restaurant::Kitchen::printKitchenValue() const
{
    std::cout << "MF Order name: " << this->orderName << std::endl;
}
