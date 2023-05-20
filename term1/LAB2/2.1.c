#include <stdio.h>

int main()
{
	int a = 1, b = 0, c = 0, d = 0;
	int num1, num2;

	while (1)
	{
		num1 = a * 1000 + b * 100 + c * 10 + d; //1000
		num2 = b * 1000 + c * 100 + d * 10 + a; //0001

		d++;
		if (d > 9)
		{
			d = 0;
			c++;
		}
		if (c > 9)
		{
			c = 0;
			b++;
		}
		if (num2 / num1 == 3)
		{
			break;
		}
	}

	printf("Answer : %d", num1);

	return 0;
}
