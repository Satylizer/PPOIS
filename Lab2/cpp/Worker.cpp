#include "Worker.h"

Worker::Worker(string workerName, int rank) : workerName(workerName), rank(rank), function(""), pay(0)
{
}

void Worker::setRank(int rank) {
	this->rank = rank;
}

int Worker::getRank()
{
	return this->rank;
}

void Worker::setFunction(string function)
{
	this->function = function;
}

string Worker::getFunction()
{
	return this->function;
}

void Worker::setPay(double pay)
{
	this->pay = pay;
}

double Worker::getPay()
{
	return this->pay;
}
