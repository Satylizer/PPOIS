#pragma once

#include<iostream>
#include<string>
#include "UsedInstruments.h"

using namespace std;

class Worker: public UsedInstruments
{
public:
	Worker(string workerName, int rank);
	void setRank(int rank);
	int getRank();
	virtual void setFunction(string function);
	string getFunction();
	void setPay(double pay);
	double getPay();

private:
	string workerName;
	string function;
	double pay;
	int rank;
};
