#pragma once

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
