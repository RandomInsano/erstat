#pragma once

#include <list>
#include <string>

#include <stdlib.h>

struct Process {
	std::string name;
	std::string user;
	size_t memort_resident;
};

class MachineInfo {
public:
	virtual int GetTermX() = 0;
	virtual int GetTermY() = 0;

	virtual std::list<Process> GetProcesses() = 0;
};

class MachineOSXInfo : public MachineInfo {
	// Nothing really is different here...

	int _GetIntEnv(const char* var, int def)
	{
		auto item = getenv ("COLUMNS");
		if (item != NULL) {
			return atoi(item);
		}

		return def;
	}

	int GetTermX() {
		return _GetIntEnv("COLUMNS", 80);
	}

	int GetTermY() {
		return _GetIntEnv("LINES", 24);
	}
};