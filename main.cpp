#include <iostream>
#include <iomanip>

#include "interface.hpp"

using namespace std;

int main(int argc, char **argv)
{
	auto info = MachineOSXInfo();

	winsize size;
	info.GetTermDimensions(size);
	cout << "Inferface: " << size.ws_col << "x" << size.ws_row << endl << endl;

	printf("%-20s %10s %4s\n",
		"Process",
		"User",
		"MemR");

	cout << string(size.ws_col, '-') << endl;

	for (auto process : info.GetProcesses())
	{
		printf("%-20s %10s %4zu\n",
			process.name.c_str(),
			process.user.c_str(),
			process.memory_resident);
	}
}
