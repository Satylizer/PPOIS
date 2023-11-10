#include "DoneWorkCheck.h"

DoneWorkCheck::DoneWorkCheck(Customer& customer, ObjectForRepair& object, Employer& employer) : customer(customer), object(object), employer(employer), paid(0), date("")
{
}

void DoneWorkCheck::customerPaid(double paid)
{
	this->paid = paid;
}

void DoneWorkCheck::verifedOrder(string date)
{
	if (paid != 0) {
		cout << "Order verifed " << date << endl;
	}
	else
	{
		return;
	}
}

