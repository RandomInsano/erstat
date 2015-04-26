#include <iostream>
#include <ncurses.h>

#include <sys/resource.h>
#include <libproc.h>
#include <assert.h>

using namespace std;

struct rusage r_usage;

int main()
{
	int pid_count;
	pid_t* pids;
	char name[256];

	cout << "Hello world!" << endl;

	if (getrusage(RUSAGE_SELF, &r_usage)) {
		printf("Problem\n");
	}

	printf("Total User CPU = %ld.%d\n",
	        r_usage.ru_utime.tv_sec,
	        r_usage.ru_utime.tv_usec);
	printf("Total System CPU = %ld.%d\n",
	        r_usage.ru_stime.tv_sec,
	        r_usage.ru_stime.tv_usec);
	
	pid_count = proc_listpids(PROC_ALL_PIDS, 0, NULL, 0);
	assert(pid_count > 0);
	pids = (pid_t*)malloc(pid_count * sizeof(pid_t));
	pid_count = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));

	for (int a = 0; a < pid_count; a++)
	{
		proc_name(pids[a], name, sizeof(name));

		printf("PID: %d (%s)\n", pids[a], name);
	}
}
