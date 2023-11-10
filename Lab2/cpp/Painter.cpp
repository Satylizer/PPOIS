#include "Painter.h"

Painter::Painter(string painterName, int rank) : Worker(painterName, rank)
{
}

void Painter::setFunction(string function)
{
	this->function = function;
}

string Painter::getFunction()
{
	return this->function;
}