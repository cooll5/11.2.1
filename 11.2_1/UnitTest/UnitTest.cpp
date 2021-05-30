#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_11_2/lab_11_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream f("test.dat", ios::binary);
			Student student;
			student.fiz = 5;
			student.mat = 5;
			student.spec = KN;
			student.prog = 5;
			f.write((char*)&student, sizeof(Student));
			f.close();
			ifstream file("test.dat", ios::binary);
			int x = SearchOne("test.dat");
			int y = SearchTwo("test.dat");
			Assert::AreEqual(x, 1);
			Assert::AreEqual(y, 3);
			f.close();
		}
	};
}
