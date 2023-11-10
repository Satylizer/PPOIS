#include "Estimator.h"

Estimator::Estimator(string estimatorName, int rank) : Worker(estimatorName, rank)
{
}

void Estimator::setFunction(string function)
{
	this->function = function;
}

string Estimator::getFunction()
{
	return this->function;
}
