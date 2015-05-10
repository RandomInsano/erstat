#include <iostream>

#include "interface.hpp"

using namespace std;

int main(int argc, char **argv)
{
	auto info = MachineOSXInfo();

	cout << "Inferface: " << info.GetTermX() << "x" << info.GetTermY() << endl;
}
