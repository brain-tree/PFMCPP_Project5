#pragma once
#include "LeakedObjectDetector.h"

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
        double annualRevenue(const double& annualProfit);
        void replaceTheOven(int newOven, int oldOven) const;
        void printKitchenValue() const;

        JUCE_LEAK_DETECTOR(Kitchen)
    };

    void makeFood(Kitchen kitchen);
    void serveDiners(Kitchen kitchen);
    float chargeMoney(const float& moneyOfMeal);
    void cleanTheKitchen(const int& amountOfAmmonia, const int& numOfSponges);
    void printRestValue() const;

    Kitchen patronsBeingServed;

    JUCE_LEAK_DETECTOR(Restaurant)
};
