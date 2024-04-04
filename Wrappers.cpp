#include "Wrappers.h"
#include "Synthesizer.h"

WrapperSynthesizer::WrapperSynthesizer(Synthesizer* synthptr) : pointerToSynthesizer(synthptr) {}

WrapperSynthesizer::~WrapperSynthesizer()
{
    delete pointerToSynthesizer;
}
