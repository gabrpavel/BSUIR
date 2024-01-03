#include <stdio.h>

int main()
{
	int A, B, C;
	int x1, y1, x2, y2, x3, y3;

	printf("Input coordinates of point A ");
	scanf_s("%d %d", &x1, &y1);

	printf("Input coordinates of point B ");
	scanf_s("%d %d", &x2, &y2);

	printf("Input coordinates of point C ");
	scanf_s("%d %d", &x3, &y3);

	A = x1 * x1 + y1 * y1;
	B = x2 * x2 + y2 * y2;
	C = x3 * x3 + y3 * y3;

	if (A < B && A < C)
	{
		printf("\nPoint A is the closest\n");
	}
	else if (B < A && B < C)
	{
		printf("\nPoint B is the closest\n");
	}
	else if (C < A && C < B)
	{
		printf("\nPoint C is the closest\n");
	}
	else printf("Correct your points\n");

	return 0;
}
