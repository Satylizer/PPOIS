#pragma once

#include<iostream>
#include<string>
#include "Worker.h"

using namespace std;

class Plasterer : public Worker
{
public:
	Plasterer(string plastererName, int rank);
	void setFunction(string function) override;
	string getFunction();

private:
	string function;
};