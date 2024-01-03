#include <stdio.h>

int main()
{
	for (int i = 1000 ; i<10000 ; i++)
	{
		if (i % 2 == 0 && i % 7 == 0 && i % 11 == 0)
		{
			if (i / 1000 + i % 1000 / 100 + i % 1000 % 100 / 10 + i % 1000 % 100 % 10 == 30)
			{
				printf("Answer : %d\n", i);
			}
		}
	}
	return 0;
}
