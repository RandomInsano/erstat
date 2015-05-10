#include <iostream>

#include "interface.hpp"

using namespace std;

int main(int argc, char **argv)
{
	auto info = MachineOSXInfo();

	winsize size;
	info.GetTermDimensions(size);
	cout << "Inferface: " << size.ws_col << "x" << size.ws_row << endl;
}
