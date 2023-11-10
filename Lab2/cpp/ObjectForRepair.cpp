#include "ObjectForRepair.h"

using namespace std;

ObjectForRepair::ObjectForRepair(string repObject) : repObject(repObject), duration(0), repairCost(0.0) {}

void ObjectForRepair::setDuration(int duration)
{
	this->duration = duration;
}

void ObjectForRepair::setRepairCost(double repairCost)
{
	this->repairCost = repairCost;
}

int ObjectForRepair::getDuration()
{
	return this->duration;
}

double ObjectForRepair::getRepairCost()
{
	return this->repairCost;
}