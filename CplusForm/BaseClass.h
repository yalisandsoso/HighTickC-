/*     Autor: YHK@  Timing: 2021/4/8 10:31 Feautres: 0.0.1
 *     This header defines the base class and shows you the base features in  
 *     "Class".
 *     
 *     The Terms contatins: constructor, const, delegating constructor, heap, stock, member variables,
 *     ctor_initializer.
 *     and so on.
 *
 *     TODO: Improved into a reusable version and upgraded features.
 */
#pragma once
#include <string>
#include <iostream>
#include <sstream>   // import istringstream

namespace VISD
{
	class BaseClass
	{
	public:
#pragma region CONSTRUCTOR
		~BaseClass();
		// BaseClass() = delete;
		// BaseClass() = default;
		// use ctor_initializer
		BaseClass();
		BaseClass(double inNumCount);
		// !!!!  NO EFFECT
		// Invaild constructor. 
		//BaseClass(std::string inNumStr);
		// delegating constructor
		BaseClass(std::string inNumStr);

		BaseClass(int inWidth, int inHeight);

		// BaseClass(const BaseClass& copyBaseClass) = default;
		// copy constructor
		BaseClass(const BaseClass& copyBaseClass);
#pragma endregion

#pragma region GET&SET
		// getter mNumCount
		const double& GetmNumCount() const;
		// setter mNumCount
		void SetmNumCount(const double& inNumCount);

		// getter mGroup
		const int& GetmGroup(int x, int y) const;
		// setter mGroup
		void SetmGroup(int x, int y, const int& group);

		// getter mFeatures
		const std::string& GetmFeatures() const;
#pragma endregion

#pragma region OVERLOAD
		// different from copy constructor
		// this is named: move assignment operator
		// or use this:
		// BaseClass& operator=(const BaseClass& bClass) = default;
		BaseClass& operator=(const BaseClass& bClass);

		/*
		* if you allocate memory dynamically,
		* and you want to prohibit other from copying or assigning value. do these:
		*	BaseClass(const BaseClass& srcBaseClass) = delete;
		*   BaseClass& operator=(const BaseClass& srcBaseClass) = delete;
		*/
#pragma endregion
		
		enum class CodeLine: int {low = 1, middle, hight};

	public:
		// friend
		// friend + Class/ Func , that allows other Class or function to visit BaseClass's all member(function, memeber variables)
		// always be used in operator overload.
		// friend BaseClass operator+(const BaseClass& bClass, const BaseClass& bClass1);
	protected:
		double stringToDouble(const std::string& inStr);
		std::string doubleToString(const double& inDouble);

	private:
		double mNumCount;
		std::string mStrName;

		// in Class-member initialize.
		// just - "static const int" type can do this in class
		static const int sVersion = 0;

		int mGroupW;
		int mGroupH;
		// To allocate memeory dynamically, you should write your own copy
		// constructor and assignment operator.
		// Shallow copy will cause memory leak. Just copy or assign data members directly from the source object to the target object.
		int** mGroup;

		static std::string mFeatures;

		// delete default constructor
		//BaseClass & mBaseClass;

		// allow the const func to change this variables.
		mutable int mNumAccess = 0;
	};
}


/*
*
*   change:  2021.4.8  yhk
*/