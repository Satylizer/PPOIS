#pragma once

#include<iostream>
#include<string>

using namespace std;

class UsedInstruments
{
public:
	UsedInstruments();
	void setInstrument(string inst);
	string getInstrument();

private:
	string usedInstruments;
};
