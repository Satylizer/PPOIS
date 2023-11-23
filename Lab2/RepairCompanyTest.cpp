#include "pch.h"
#include "CppUnitTest.h"
#include "..\PPOIS2\Customer.h"
#include "..\PPOIS2\DoneWorkCheck.h"
#include "..\PPOIS2\Employer.h"
#include "..\PPOIS2\Estimator.h"
#include "..\PPOIS2\ObjectForRepair.h"
#include "..\PPOIS2\Painter.h"
#include "..\PPOIS2\Plasterer.h"
#include "..\PPOIS2\Plumber.h"
#include "..\PPOIS2\UsedInstruments.h"
#include "..\PPOIS2\Worker.h"
#include "..\PPOIS2\Customer.cpp"
#include "..\PPOIS2\DoneWorkCheck.cpp"
#include "..\PPOIS2\Employer.cpp"
#include "..\PPOIS2\Estimator.cpp"
#include "..\PPOIS2\ObjectForRepair.cpp"
#include "..\PPOIS2\Painter.cpp"
#include "..\PPOIS2\Plasterer.cpp"
#include "..\PPOIS2\Plumber.cpp"
#include "..\PPOIS2\UsedInstruments.cpp"
#include "..\PPOIS2\Worker.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace RepairCompany
{
	TEST_CLASS(RepairCompany)
	{
	public:
		
		TEST_METHOD(customer)
		{
			Customer customer("Victor", "+37533...");
			Assert::IsNotNull(&customer);
			string example = "Victor";
			Assert::AreEqual(example, customer.getCustomerName());
			customer.offerOrder();
			customer.placeOrder();
			Assert::IsTrue(true);
		}
		TEST_METHOD(employer)
		{
			Employer employer("Den", "+37529...");
			employer.setPrice(500);
			double example = 500;
			Assert::AreEqual(example, employer.getPrice());
			employer.endWork();
			Assert::IsTrue(true);
		}
		TEST_METHOD(worker)
		{
			Worker worker("Vasia", 3);
			worker.setFunction("repair");
			string example1 = "repair";
			Assert::AreEqual(example1, worker.getFunction());
			worker.setInstrument("spatula");
			string example2 = "spatula";
			Assert::AreEqual(example2, worker.getInstrument());
			worker.setPay(300);
			double example3 = 300;
			Assert::AreEqual(example3, worker.getPay());
			worker.setRank(2);
			int example4 = 2;
			Assert::AreEqual(example4, worker.getRank());
		}
		TEST_METHOD(objectForRepair)
		{
			ObjectForRepair object("kitchen");
			object.setRepairCost(500);
			double example1 = 500;
			Assert::AreEqual(example1, object.getRepairCost());
			object.setDuration(2);
			int example2 = 2;
			Assert::AreEqual(example2, object.getDuration());
		}
		TEST_METHOD(estimator)
		{
			Estimator estimator("Andrew", 4);
			estimator.setFunction("writing");
			string example = "writing";
			Assert::AreEqual(example, estimator.getFunction());
		}
		TEST_METHOD(plumber)
		{
			Plumber plumber("Andrew", 4);
			plumber.setFunction("repairPipes");
			string example = "repairPipes";
			Assert::AreEqual(example, plumber.getFunction());
		}
		TEST_METHOD(plasterer)
		{
			Plasterer plasterer("Andrew", 4);
			plasterer.setFunction("spatula");
			string example = "spatula";
			Assert::AreEqual(example, plasterer.getFunction());
		}
		TEST_METHOD(painter)
		{
			Painter painter("Andrew", 4);
			painter.setFunction("paint");
			string example = "paint";
			Assert::AreEqual(example, painter.getFunction());
		}
		TEST_METHOD(usedInstruments)
		{
			UsedInstruments inst;
			inst.setInstrument("spatula");
			string example = "spatula";
			Assert::AreEqual(example, inst.getInstrument());
		}
		TEST_METHOD(doneWorkCheck)
		{
			Customer customer("Victor", "+37533...");
			ObjectForRepair object("kitchen");
			Employer employer("Den", "+37529...");
			DoneWorkCheck done(customer, object, employer);
			done.customerPaid(1000);
			done.verifedOrder("11.07.2023");
			Assert::IsTrue(true);
		}
	};
}
