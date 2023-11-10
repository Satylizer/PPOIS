#include "Employer.h"

using namespace std;

Employer::Employer(string name, string contacts) : employerName(name), employerContacts(contacts), price(0)
{
}

void Employer::setPrice(double price)
{
	this->price = price;
}

double Employer::getPrice()
{
	return this->price;
}

void Employer::endWork()
{
	cout << "Work ended" << endl;
}