#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void task1();
void task2();
void task3();


void your_arr(float *arr, int n);
void random_arr(float *arr, int n);
int indMax(float arr[100], int n);



void task1()
{
	int n, choose, C, cnt = 0, max_ind;
	float arr[100], max;
	float product;

	srand(time(NULL));

	printf("\nInput next number:\n1 - Your array\n2 - Random array\n");
	printf("Your answer: ");
	while (scanf_s("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose > 2)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	

	printf("\nInput quantity of elements: ");
	while (scanf_s("%d", &n) != 1 || getchar() != '\n' || n < 1 || n > 100)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	rewind(stdin);

	if (choose==1)
	{
		your_arr(arr, n);
	}
	else if (choose == 2)
	{
		random_arr(arr, n);
	}
	
	printf("\nInput C: ");
	while (scanf_s("%d", &C)!= 1 || getchar()!= '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > C)
		{
			cnt++;
		}
	}

	printf("\nValue of elements higher C: %d\n", cnt);

	max_ind = indMax(arr, n);
	product = 1;
	
	for (int i = max_ind + 1; i < n; i++)
	{
		product *= arr[i];
	}

	printf("Product: %.1f\n", product);

}
void task2()
{
	int n, choose, k;
	float arr[100];
	
	srand(time(NULL));

	printf("\nInput next number:\n1 - Your array\n2 - Random array\n");
	printf("Your answer: ");
	while (scanf_s("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose > 2)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}

	printf("\nInput quantity of elements: ");
	while (scanf_s("%d", &n) != 1 || getchar() != '\n' || n < 1 || n > 100)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	rewind(stdin);

	if (choose == 1)
	{
		your_arr(arr, n);
	}
	else if (choose == 2)
	{
		random_arr(arr, n);
	}

	printf("\nInput k: ");
	while (scanf_s("%d", &k) != 1 || getchar() != '\n' || k < 1 || k > n)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}

	for (int i = k; i < n+1; i=k+1+i)
	{
		n++;
		for (int j = n-1; j > i ; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[i] = 0;
	}


	for (int i = 0; i < n; i++)
	{
		printf("%.1f ", arr[i]);
	}
	printf("\n");
}
void task3()
{
	int n, choose, counter = 0, number_of_repeat = 0, most_common = 0;
	int arr[100];

	srand(time(NULL));

	printf("\nInput next number:\n1 - Your array\n2 - Random array\n");
	printf("Your answer: ");
	while (scanf_s("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose > 2)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}


	printf("\nInput quantity of elements: ");
	while (scanf_s("%d", &n) != 1 || getchar() != '\n' || n < 1 || n > 100)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	rewind(stdin);

	if (choose == 1)
	{
		for (int i = 0; i < n; i++)
		{
			printf("Element %d: ", i + 1);
			if (scanf_s("%d", &arr[i]) != 1 || getchar() != '\n')
			{
				i--;
				printf("Error. Try again: ");
				rewind(stdin);
			}
			else
			{
				continue;
			}
			printf("\n");
		}
	}
	else if (choose == 2)
	{
		for (int j = 0; j < n; j++)
		{
			arr[j] = rand() % 10;
			printf("%d element: %d\n", j + 1, arr[j]);
		}
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				counter++;
			}
		}
		if (counter > number_of_repeat)
		{
			number_of_repeat = counter;
			most_common = arr[i];
		}
		counter = 0;
	}
	printf("\nQuantity of repeat: %d\n", number_of_repeat);
	printf("Most common element: %d\n", most_common);

	printf("\n%d\n", most_common);
}


int indMax(float arr[100], int n)
{
	int max_ind = 0;
	float max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
			max_ind = i;
		}
	}
	return max_ind;
}
void random_arr(float *arr, int n)
{
	for (int j = 0; j < n; j++)
	{
		arr[j] = (double)(rand() % 200) / 10; 
		printf("%d element: %.1f\n", j+1,arr[j]);
	}
	return 1;
}
void your_arr(float *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Element %d: ", i + 1);
		if (scanf_s("%f", &arr[i]) != 1 || getchar() != '\n')
		{
			i--;
			printf("Error. Try again: ");
			rewind(stdin);
		}
		else
		{
			continue;
		}
		printf("\n");
	}
}

