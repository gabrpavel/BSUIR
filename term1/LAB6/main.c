#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include "header.h"

int main()
{
	int task;
	while (1)
	{
		srand(time(NULL));
		setlocale(LC_ALL, "rus");
		printf("Input number of task 1-2 (0 to stop): ");
		while (scanf_s("%d", &task) != 1 || task < 0 || task > 2 || getchar() != '\n')
		{
			printf("Error! Try again...\n");
			rewind(stdin);
		}
		rewind(stdin);
		system("cls");
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

		else if (task == 0)
		{
			break;
		}
	}
	return 0;
}