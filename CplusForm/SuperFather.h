#pragma once
#include <iostream>

namespace VISD
{
	class SuperFather
	{
	public:
		SuperFather();
		virtual ~SuperFather();
		virtual void SetmFatherVersion(const float& inVersion);
		virtual void PadPad();
	private:
		float mfatherVersion;
	};
}

