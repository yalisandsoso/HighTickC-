#include "SuperFather.h"

using namespace VISD;
SuperFather::SuperFather():
	mfatherVersion(0.1)
{
}

SuperFather::~SuperFather()
{
}

void SuperFather::SetmFatherVersion(const float & inVersion)
{
	mfatherVersion = inVersion;
}

void VISD::SuperFather::PadPad()
{
	std::cout << "WO SHI NI BABA O (-.-)'" << std::endl;
}
