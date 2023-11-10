#pragma once

#include<iostream>
#include<string>
#include "Worker.h"

using namespace std;

class Plumber : public Worker
{
public:
	Plumber(string plumberName, int rank);
	void setFunction(string function) override;
	string getFunction();

private:
	string function;
};
