#include "Plumber.h"

Plumber::Plumber(string plumberName, int rank) : Worker(plumberName, rank)
{
}

void Plumber::setFunction(string function)
{
	this->function = function;
}

string Plumber::getFunction()
{
	return this->function;
}