/*
*     Change List:
*                      YHK    base features add.     2021.4.8.
*/
#include "BaseClass.h"

using namespace VISD;

// initial static member
std::string BaseClass::mFeatures = "0.0.1";

BaseClass::~BaseClass()
{
	for (int i = 0; i < this->mGroupW; i++)
	{
		delete[] this->mGroup[i];
	}

	delete[] this->mGroup;
	this->mGroup = nullptr;
}

BaseClass::BaseClass(): 
	mNumCount(0.0), mStrName("")
/*
*   ctor_initializer: force to use this type constructor
*     Quote Objects, const member variables, has no default constructor func Object, Bass Class that has no default constructor
*   
*   the order to initialize dependent on the order defined
*/
{
	mFeatures = "0.0.1";
}


BaseClass::BaseClass(double inNumCount)
{
	this->mNumCount = inNumCount;
}

//BaseClass::BaseClass(std::string inNumStr)
///*
//*       NO EFFECT.
//*       DO NOT USE THIS!!!!
//*/
//{
//	BaseClass(stringToDouble(inNumStr));
//}


BaseClass::BaseClass(std::string inNumStr):
	BaseClass(stringToDouble(inNumStr))
/*
*   delegating constructor
*/
{
}

BaseClass::BaseClass(int inWidth, int inHeight):
	mGroupW(inWidth),mGroupH(inHeight)
{
	mGroup = new int*[inHeight];

	for (int i = 0; i < mGroupW; i++)
	{
		mGroup[i] = new int[mGroupH];
	}
}

BaseClass::BaseClass(const BaseClass & copyBaseClass):
	mNumCount(copyBaseClass.mNumCount),
	mStrName(copyBaseClass.mStrName)
{
	mFeatures = "0.0.1";
	std::cout << "BaseClass- copy Constructor..." << std::endl;

	mGroupW = copyBaseClass.mGroupW;
	mGroupH = copyBaseClass.mGroupH;
	// no need to delete mGroup here
	// because this is copy constructor, here has no mGroup before
	mGroup = new int*[mGroupW];

	for (int i = 0; i < mGroupW; i++)
	{
		mGroup[i] = new int[mGroupH];
	}

	for (int i = 0; i < mGroupH; i++)
	{
		for (int j = 0; j < mGroupH; j++)
		{
			mGroup[i][j] = copyBaseClass.mGroup[i][j];
		}
	}
}

const double & BaseClass::GetmNumCount() const
{
	return this->mNumCount;
}

void BaseClass::SetmNumCount(const double & inNumCount)
{
	this->mNumCount = inNumCount;
}

const int & BaseClass::GetmGroup(int x, int y) const
{
	if (x < mGroupW && y < mGroupH)
		return this->mGroup[x][y];
}

void BaseClass::SetmGroup(int x, int y, const int & group)
{
	if (x < mGroupW && y < mGroupH)
		this->mGroup[x][y] = group;
	else
	{
		throw std::out_of_range("[Error]mGroup: x, y out of range!");
	}
}

const std::string & VISD::BaseClass::GetmFeatures() const
{
	// change mutable int 
	this->mNumAccess = 0;

	return mFeatures;
}

BaseClass & BaseClass::operator=(const BaseClass & bClass)
{
	mFeatures = bClass.mFeatures;
	// check for self-assignment.
	if (this == &bClass)
	{
		return *this;
	}

	// free the old memory
	for (int i = 0; i < this->mGroupW; i++)
	{
		delete[] this->mGroup[i];
	}
	delete[] this->mGroup;
	this->mGroup = nullptr;

	// copy the new memory.
	mGroupW = bClass.mGroupW;
	mGroupH = bClass.mGroupH;
	mGroup = new int*[mGroupW];

	for (int i = 0; i < mGroupW; i++)
	{
		mGroup[i] = new int[mGroupH];
	}

	for (int i = 0; i < mGroupW; i++)
	{
		for (int j = 0; j < mGroupH; j++)
		{
			mGroup[i][j] = bClass.mGroup[i][j];
		}
	}

	this->mNumCount = bClass.mNumCount;
	this->mStrName = bClass.mStrName;
	return *this;
}

double BaseClass::stringToDouble(const std::string & inStr)
{
	double Temp;
	std::istringstream istr(inStr);
	
	istr >> Temp;
	
	if (istr.fail() || !istr.eof())
	{
		return 0.0;
	}

	return Temp;
}

std::string BaseClass::doubleToString(const double & inDouble)
{
	std::ostringstream ostr;

	ostr << inDouble;

	return ostr.str();
}
