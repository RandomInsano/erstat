#pragma once

#include <list>
#include <string>

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>


struct Process {
	std::string name;
	std::string user;
	size_t memory_resident;
};

class MachineInfo {
public:
	virtual void GetTermDimensions(winsize& term_size) = 0;

	virtual std::list<Process> GetProcesses() = 0;
};

class MachineOSXInfo : public MachineInfo {
public:
	void GetTermDimensions(winsize& term_size) {
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_size);
	}

	std::list<Process> GetProcesses() {
		auto processes = std::list<Process>();
		Process* proc;

		for (auto i = 0; i < 100; i++) {
			proc = new Process();
			proc->name = "Process" + std::to_string(i);
			proc->user = "edwin";
			proc->memory_resident = 12;

			processes.push_back(*proc);
		}

		return processes;
	}
};