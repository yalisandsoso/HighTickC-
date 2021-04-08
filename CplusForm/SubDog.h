#pragma once
#include "SuperFather.h"

namespace VISD
{
	class SubDog: SuperFather
	{
	public:
		virtual void PadPad() override;
		void DieDie();
	private:
		std::string mSubDogName;
	};
}

