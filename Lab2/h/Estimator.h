#pragma once

#include<iostream>
#include<string>
#include "Worker.h"

using namespace std;

class Estimator : public Worker
{
public:
	Estimator(string estimatorName, int rank);
	void setFunction(string function) override; 
	string getFunction();

private:
	string function;
};
