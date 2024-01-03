#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int number_of_row(int size1)
{
	printf("Input number of rows: ");
	while (scanf_s("%d", &size1) != 1 || getchar() != '\n' || size1 < 1 || size1 > 50)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return size1;
}
int number_of_col(int size2)
{
	printf("Input number of columns: ");
	while (scanf_s("%d", &size2) != 1 || getchar() != '\n' ||size2 < 1 || size2 > 50)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return size2;
}
int choose_input(int choice) 
{
	printf("\nInput next number:\n1 - Your matr\n2 - Random matr\n");
	printf("Your answer: ");
	while (scanf_s("%d", &choice) != 1 || getchar() != '\n' || choice < 1 || choice > 2)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return choice;
}
int square_size(size)
{
	printf("Input number of elements (NxN): ");
	while (scanf_s("%d", &size) != 1 || getchar() != '\n' || size < 1 || size > 50)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return size;
}

int random_matr(int size1, int size2, int matrix[50][50])
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			matrix[i][j] = (rand() % 20) - 5;
		}
	}
}
int your_matr(int size1, int size2, int matrix[50][50])
{
	system("cls");
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			printf("Element %d %d: ", i + 1, j + 1);
			if (scanf_s("%d", &matrix[i][j]) != 1 || getchar() != '\n')
			{
				j--;
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
}

int input_matr(int size1, int size2, int choice, int matrix[50][50])
{
	if (choice == 1)
		your_matr(size1, size2, matrix);
	if (choice == 2)
		random_matr(size1, size2, matrix);
}
void print_matr(int row, int col, int matr[50][50])
{
	for (int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%4d", matr[i][j]);
		}
		printf("\n");
	}
}

//task 1
void number_of_0_in_columns(int size2, int size1, int matrix[50][50])
{
	int cnt = 0;
	for (int j = 0; j < size1; j++)
	{
		for (int i = 0; i < size2; i++)
		{
			if (matrix[i][j] == 0)
			{
				cnt++;
				break;
			}
		}
	}
	printf("\nNumber of columns with 0: %d\n", cnt);
}
void number_of_ROW_with_most_common(int size1, int size2, int matrix[50][50])
{
	int cnt = 0, number_of_repeat = 0, most_common = 0, row_with_repeat = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			for (int k = j; k < size1; k++)
			{
				if (matrix[i][j] == matrix[i][k])
				{
					cnt++;
				}
			}
			if (cnt > number_of_repeat)
			{
				number_of_repeat = cnt;
				most_common = matrix[i][j];
				row_with_repeat = i;
			}
			cnt = 0;
		}
	}
	printf("Most common element located in %d row\n", row_with_repeat + 1);
}

//task 2
int first_element_in_ROWwithNULL(int size1, int size2, int matrix[50][50])
{
	int row_with_null = -1, deductible = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (matrix[i][j] == 0)
			{
				row_with_null = i;
				deductible = matrix[row_with_null][0];
				break;
			}
		}
		if (row_with_null != -1)
		{
			break;
		}
	}
	if (row_with_null == -1)
		printf("\nThere are no rows with null\n");
	else
		printf("\nNumber of row with null: %d\n\n", row_with_null + 1);
	return deductible;
}
void matrix_minus_deductible(int deductible, int row, int col, int matr[50][50])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matr[i][j] -= deductible;
			printf("%4d", matr[i][j]);
		}
		printf("\n");
	}
}

//task 3
void find_minEVEN_element(int size, int matrix[50][50])
{
	int center = size / 2;
	int min_element = matrix[size - 1][size - 1];

	int flag = 0;

	for (int i = size - 1; i >= center; i--)
	{
		for (int j = flag; j < size - flag; j++)
		{
			if (matrix[i][j] % 2 == 0 && matrix[i][j] < min_element)
			{
				min_element = matrix[i][j];
			}
		}
		flag++;
	}
	printf("\nMin even element: %d\n", min_element);
}


task1() 
{
	srand(time(NULL));

	int matr[50][50];
	int row = 10, col = 10, choose = 0;

	row = number_of_row(row);
	col = number_of_col(col);
	choose = choose_input(choose);
	
	input_matr(row, col, choose, matr);
	system("cls");
	print_matr(row, col, matr);

	number_of_0_in_columns(row, col, matr);
	number_of_ROW_with_most_common(row, col, matr);

}

task2()
{
	srand(time(NULL));

	int matr[50][50];
	int row = 10, col = 10, choose = 0;

	row = number_of_row(row);
	col = number_of_col(col);
	choose = choose_input(choose);

	input_matr(row, col, choose, matr);
	system("cls");
	print_matr(row, col, matr);

	int deductible = first_element_in_ROWwithNULL(row, col, matr);
	matrix_minus_deductible(deductible, row, col, matr);
}

task3()
{
	srand(time(NULL));

	int matr[50][50];
	int size = 0, choose = 0;

	size = square_size(size);
	choose = choose_input(choose);

	input_matr(size, size, choose, matr);
	system("cls");
	print_matr(size, size, matr);

	find_minEVEN_element(size, matr);
}