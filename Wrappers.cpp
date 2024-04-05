#include "Wrappers.h"
#include "Synthesizer.h"
#include "Restaurant.h"
#include "Bank.h"

WrapperSynthesizer::WrapperSynthesizer(Synthesizer* synthptr) : pointerToSynthesizer(synthptr) {}

WrapperSynthesizer::~WrapperSynthesizer()
{
    delete pointerToSynthesizer;
}

WrapperKeyboard::WrapperKeyboard(Synthesizer::Keyboard* keysptr) : pointerToKeyboard(keysptr) {}

WrapperKeyboard::~WrapperKeyboard()
{
    delete pointerToKeyboard;
}

WrapperRestaurant::WrapperRestaurant(Restaurant* restptr) : pointerToRestaurant(restptr) {}

WrapperRestaurant::~WrapperRestaurant()
{
    delete pointerToRestaurant;
}

WrapperKitchen::WrapperKitchen(Restaurant::Kitchen* kitptr) : pointerToKitchen(kitptr) {}

WrapperKitchen::~WrapperKitchen()
{
    delete pointerToKitchen;
}

WrapperBank::WrapperBank(Bank* bankptr) : pointerToBank(bankptr) {}

WrapperBank::~WrapperBank()
{
    delete pointerToBank;
}

WrapperEffectsRack::WrapperEffectsRack(EffectsRack* fxptr) : pointerToEffectsRack(fxptr) {}

WrapperEffectsRack::~WrapperEffectsRack()
{
    delete pointerToEffectsRack;
}

WrapperDiningRoom::WrapperDiningRoom(DiningRoom* drptr) : pointerToDiningRoom(drptr) {}

WrapperDiningRoom::~WrapperDiningRoom()
{
    delete pointerToDiningRoom;
}
