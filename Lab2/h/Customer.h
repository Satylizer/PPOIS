#pragma once

#include<iostream>
#include<string>

using namespace std;

class Customer {
public:
	Customer(string name, string contacts);
	void placeOrder();
	void offerOrder();
	string getCustomerName();

private:
	string customerName;
	string customerContacts;
	string customerAddress;
};