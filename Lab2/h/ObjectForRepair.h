#pragma once

#include "Employer.h"
#include<iostream>
#include<string>

using namespace std;

class ObjectForRepair
{
public:
	ObjectForRepair(string repObject);
	void setDuration(int duration);
	void setRepairCost(double repairCost);
	int getDuration();
	double getRepairCost();

private:
	string repObject;
	int duration;
	double repairCost;
};