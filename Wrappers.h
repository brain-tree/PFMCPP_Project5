#pragma once

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

