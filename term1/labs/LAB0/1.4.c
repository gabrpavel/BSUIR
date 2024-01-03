#include <stdio.h>

int main()
{
	
	int choose;

	printf("Input number of term ");
	scanf_s("%d", &choose);

	switch (choose)
	{
	case 1:
		printf("In 1 term you will learn : informatics, foreign language");
		break;
	case 2:
		printf("In 2 term you will learn : informatics, foreign language");
		break;
	case 3:
		printf("In 3 term you will learn : foreign language, math, culturology");
		break;
	case 4:
		printf("In 4 term you will learn : foreign language, math, culturology");
		break;
	default:
		printf("Try again");
	}

	return 0;
}
