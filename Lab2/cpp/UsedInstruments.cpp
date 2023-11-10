#include "UsedInstruments.h"

using namespace std;

UsedInstruments::UsedInstruments() : usedInstruments("")
{
}

void UsedInstruments::setInstrument(string inst)
{
	this->usedInstruments = inst;
}

string UsedInstruments::getInstrument()
{
	return this->usedInstruments;
}
