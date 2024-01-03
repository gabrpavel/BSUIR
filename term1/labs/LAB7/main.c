#include "header.h"
int main()
{
	void (*fptr)() = NULL;
	int restart = 1, task;
	while (restart)
	{
		choose_task(&task);
		if (task == 1)
			fptr = task1;
		else
			fptr = task2;
		fptr();
		reccurence(&restart);
	}
	return 0;
}