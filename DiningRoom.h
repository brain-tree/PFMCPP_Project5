#pragma once
#include "LeakedObjectDetector.h"
#include "Restaurant.h"

struct DiningRoom
{
    DiningRoom();
    ~DiningRoom();
    Restaurant table;
    Restaurant counter;
    Restaurant::Kitchen foyer;
    int amountOfSeatedCustomers = 20;

    void seatACustomer();
    void counterSeating(const float& stools);
    void printCustomersSeated() const;

    JUCE_LEAK_DETECTOR(DiningRoom)
};
