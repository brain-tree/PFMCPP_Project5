#pragma once
#include "Synthesizer.h"
#include "Restaurant.h"
#include "Bank.h"
#include "EffectsRack.h"
#include "DiningRoom.h"

struct WrapperSynthesizer
{
    WrapperSynthesizer(Synthesizer* synthptr);
    ~WrapperSynthesizer();

    Synthesizer* pointerToSynthesizer = nullptr;
};

struct WrapperKeyboard
{
    WrapperKeyboard(Synthesizer::Keyboard* keysptr);
    ~WrapperKeyboard();

    Synthesizer::Keyboard* pointerToKeyboard = nullptr;
};

struct WrapperRestaurant
{
    WrapperRestaurant(Restaurant* restptr);
    ~WrapperRestaurant();

    Restaurant* pointerToRestaurant = nullptr;
};

struct WrapperKitchen
{
    WrapperKitchen(Restaurant::Kitchen* kitptr);
    ~WrapperKitchen();

    Restaurant::Kitchen* pointerToKitchen = nullptr;
};

struct WrapperBank
{
    WrapperBank(Bank* bankptr);
    ~WrapperBank();

    Bank* pointerToBank = nullptr;
};

struct WrapperEffectsRack
{
    WrapperEffectsRack(EffectsRack* fxptr);
    ~WrapperEffectsRack();

    EffectsRack* pointerToEffectsRack = nullptr;
};

struct WrapperDiningRoom
{
    WrapperDiningRoom(DiningRoom* drptr);
    ~WrapperDiningRoom();

    DiningRoom* pointerToDiningRoom = nullptr;
};
