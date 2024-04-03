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
