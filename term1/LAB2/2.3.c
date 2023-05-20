#include <stdio.h>

int main()
{
	int a = 1, b = 1, d = 2, num;
	printf("Input number ");

	while (scanf_s("%d", &num) != 1)
	{
		printf("Error! Try again.\n");
		rewind(stdin);
	}

	if (num == 1)
	{
		printf("True");
		return 0;
	}

	if (num<0)
	{
		printf("Your number is negative. Try again");
		return 0;
	}

	while(num>d)
	{
		d = b + a;
		a = b;
		b = d;
	}

	if (num == d)
	{
		printf("True");
	}

	else
	{
		printf("False");
	}

	return 0;
}
