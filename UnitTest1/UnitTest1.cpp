#include "pch.h"
#include "CppUnitTest.h"
#include "../11_4/11_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream f("test.dat", ios::binary);
			Rep p;
			p.fiz = 3;
			p.elect = 3;
			p.prog = 3;
			p.web = 3;
			p.math = 3;
			f.write((char*)&p, sizeof(Rep));
			f.close();
			ifstream file("test.dat", ios::binary);
			bool x = StudThree("test.dat");
			Assert::AreEqual(x, true);
			f.close();
		}
	};
}
