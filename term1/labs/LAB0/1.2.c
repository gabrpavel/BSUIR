#include <stdio.h>

int main()
{
	int a, b, c, d;

	printf("Input 3 numbers\n");
	scanf_s("%d %d %d", &a, &b, &c);

	if (a > b && a > c)
	{
		d = a;
	}
	else if (b > a && b > c)
	{
		d = b;
	}
	else
	{
		d = c;
	}

	printf("The biggest number is %d\n", d);
	return 0;
}
