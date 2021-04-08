/*
*   For test.
*
*
*
*
*/

#include "BaseClass.h"
#include "SubDog.h"
#include <iostream>

#define DEBUG_NUM 2

using namespace VISD;

void testBaseClass();

void testSubDog();

int main()
{
	testBaseClass();
	testSubDog();
}

void testBaseClass()
{
#if DEBUG_NUM == 1
	BaseClass baseClass1(2.3);
	double inCount = 3.4;
	baseClass1.SetmNumCount(inCount);  // "double" copy constructor function will be run.

	std::cout << baseClass1.GetmNumCount() << std::endl;
	std::cout << "SetmNumCount end. delete inCount copy version, but inCount is still living." << std::endl;
	std::cout << inCount << std::endl;

	auto baseClass2 = std::make_unique<BaseClass>(120);
	auto baseClass3 = std::make_unique<BaseClass>(110);
	*baseClass2 = baseClass1 = *baseClass3;

	std::cout << "baseClass1: " << baseClass1.GetmNumCount() << std::endl;
	std::cout << "baseClass2: " << baseClass2->GetmNumCount() << std::endl;
	std::cout << "baseClass3: " << baseClass3->GetmNumCount() << std::endl;
#endif
}

void testSubDog()
{
#if DEBUG_NUM == 2
	SubDog subdog;
	subdog.DieDie();
	subdog.PadPad();

#endif
}
