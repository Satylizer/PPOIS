#pragma once

#include<iostream>
#include<string>
#include "Worker.h"

using namespace std;

class Painter : public Worker
{
public:
	Painter(string painterName, int rank);
	void setFunction(string function) override;
	string getFunction();

private:
	string function;
};
