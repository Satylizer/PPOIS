#pragma once

#include "Customer.h"
#include "ObjectForRepair.h"
#include "Employer.h"
#include<iostream>
#include<string>

using namespace std;

class DoneWorkCheck {
public:
	DoneWorkCheck(Customer& customer, ObjectForRepair& object, Employer& employer);
	void customerPaid(double paid);
	void verifedOrder(string date);

private:
	Customer& customer;
	ObjectForRepair& object;
	Employer& employer;
	string date;
	double paid;
}; 
