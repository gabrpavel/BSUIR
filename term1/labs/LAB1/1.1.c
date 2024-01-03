#include <stdio.h>

int main()
{
	float R, length, square;

	printf("Input radius to calculate length and square\t");
	scanf_s("%f", &R);
	if (R<0)
	{
		printf("Try again\n");
	}
	else
	{
		length = 2 * 3.14 * R;
		printf("Length = %.2f\n", length);

		square = 3.14 * R * R;
		printf("Square = %.2f", square);
	}
		

	return 0;
}
