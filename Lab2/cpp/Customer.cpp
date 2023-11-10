#include<iostream>
#include<string>
#include "Customer.h"

using namespace std;

Customer::Customer(string name, string contacts) : customerName(name), customerContacts(contacts) {}

void Customer::placeOrder() {
    cout << "Customer: " << this->customerName << " has placed an order" << endl;
}

void Customer::offerOrder()
{
    cout << "Customer: " << this->customerName << " has offered an order" << endl;
}

string Customer::getCustomerName() {
    return this->customerName;
}