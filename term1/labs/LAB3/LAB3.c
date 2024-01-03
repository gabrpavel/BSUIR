#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "function.h"

int main()
{
	int task;
	while (1)
	{
		printf("Input the task number (0 to stop): ");
		while(scanf_s("%d", &task) != 1 || task < 0 || task > 3 || getchar() != '\n')
		{
			printf("Error! Try again...\n");
			rewind(stdin);
		}
		rewind(stdin);

		if (task == 1)
		{
			task1();
			system("pause");
			system("cls");
			continue;
		}

		else if (task == 2)
		{
			task2();
			system("pause");
			system("cls");
			continue;
		}

		else if (task == 3)
		{
			task3();
			system("pause");
			system("cls");
			continue;
		}

		else if (task == 0)
		{
			break;
		}
	}
	return 0;
}
