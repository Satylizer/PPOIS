#include<iostream>
#include<string>
#include "Customer.h"
#include "DoneWorkCheck.h"
#include "Employer.h"
#include "ObjectForRepair.h"
#include "Painter.h"
#include "Plasterer.h"
#include "Plumber.h"
#include "UsedInstruments.h"
#include "Worker.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	Employer employer("Den", "+37529...");
	employer.setPrice(500);
	Customer customer("Victor", "+37533...");
	customer.offerOrder();
	ObjectForRepair kitchen("kitchen");
	kitchen.setDuration(2);
	kitchen.setRepairCost(1000);
	Plumber plumber("Ivan", 2);
	plumber.setInstrument("Spatula");
	employer.endWork();
	DoneWorkCheck endWork(customer, kitchen, employer);
	endWork.customerPaid(1500);
	endWork.verifedOrder("11.07.23");

	return 0;
}