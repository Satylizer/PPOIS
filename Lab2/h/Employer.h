#pragma once

#include<iostream>
#include<string>

using namespace std;

class Employer
{
public:
	Employer(string name, string contacts);
	void setPrice(double price);
	double getPrice();
	void endWork();

private:
	string employerName;
	string employerContacts;
	double price;
};