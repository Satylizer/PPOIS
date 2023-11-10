#include "Plasterer.h"

Plasterer::Plasterer(string plastererName, int rank) : Worker(plastererName, rank)
{
}

void Plasterer::setFunction(string function)
{
	this->function = function;
}

string Plasterer::getFunction()
{
	return this->function;
}