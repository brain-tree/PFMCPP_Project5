#pragma once
#include "Synthesizer.h"
#include "Restaurant.h"
#include "Bank.h"
#include "EffectsRack.h"
#include "DiningRoom.h"

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

struct WrapperBank
{
    WrapperBank(Bank* bankptr) : pointerToBank(bankptr) {}
    ~WrapperBank()
    {
        delete pointerToBank;
    }

    Bank* pointerToBank = nullptr;
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

struct WrapperDiningRoom
{
    WrapperDiningRoom(DiningRoom* drptr) : pointerToDiningRoom(drptr) {}
    ~WrapperDiningRoom()
    {
        delete pointerToDiningRoom;
    }

    DiningRoom* pointerToDiningRoom = nullptr;
};
