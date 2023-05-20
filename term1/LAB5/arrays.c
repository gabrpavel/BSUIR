#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int numberOFrows(int row)
{
	while (scanf_s("%d", &row) != 1 || getchar() != '\n' || row < 1 || row > 100)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return row;
}
int numberOFcolumns(int col)
{
	while (scanf_s("%d", &col) != 1 || getchar() != '\n' || col < 1 || col > 100)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return col;
}
int chooseINPUT(int choose)
{
	while (scanf_s("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose > 2)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return choose;
}

void memory(int*** mas, int row, int col)
{
	*mas = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
		*(*mas + i) = (int*)malloc(col * sizeof(int));
}

void random_row(int* mas, int col)
{
	for (int i = 0; i < col; i++)
		mas[i] = (rand() % 20) - 5;
}
void your_row(int* mas, int col, int j)
{
	for (int i = 0; i < col; i++)
	{
		printf("Element %d %d: ", j, i + 1);
		if (scanf_s("%d", &mas[i]) != 1 || getchar() != '\n')
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

void input_row(int* mas, int col, int choose, int j)
{
	if (choose == 1)
		your_row(mas, col, j);
	else if (choose == 2)
		random_row(mas, col);
}
void input_matr(int** mas, int row, int col, int choose, int j)
{
	for (int i = 0; i < row; i++)
	{
		input_row(*(mas + i), col, choose, j);
	}
}
void input_1mas(int** mas, int row, int* col)
{
	for (int i = 0; i < row; i++)
	{
		printf("Input number of elements in %d row: ", i + 1);
		while (scanf_s("%d", &col[i]) != 1 || getchar() != '\n' || col[i] < 1)
		{
			printf("Error! Try again\n");
			rewind(stdin);
		}
		mas[i] = (int*)malloc(col[i] * sizeof(int));
		for (int j = 0; j < col[i]; j++)
		{
			printf("Element %d %d: ", i + 1, j + 1);
			while (scanf_s("%d", &mas[i][j]) != 1 || getchar() != '\n' || mas[i][j] < 1)
			{
				printf("Error! Try again\n");
				rewind(stdin);
			}
		}
		printf("\n");
	}
}

int col_with_biggestSUM(int** mas, int row, int col)
{
	int sum = 0, MAXsum = 0, deleted_col = 0;

	for (int i = 0; i < row; i++)
		MAXsum += mas[i][0];

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			sum += mas[j][i];
		}
		if (sum >= MAXsum)
		{
			MAXsum = sum;
			deleted_col = i;
		}
		sum = 0;
	}
	return deleted_col;
}

void delete_two_digit_numbers(int** mas, int row, int* col)
{
	for (int i = row - 1; i >= 0; i--)
	{
		for (int j = col[i] - 1; j >= 0; j--)
		{
			if (mas[i][j] >= 10 && mas[i][j] <= 99)
			{
				for (int k = j; k < col[i] - 1; k++)
					mas[i][k] = mas[i][k + 1];
				col[i]--;
				mas[i] = (int*)realloc(mas[i], col[i] * sizeof(int));
			}
		}
	}
}
void delete_col_with_biggestSUM(int** mas, int* col, int row, int deleted_col)
{
	for (int j = deleted_col; j < *col - 1; j++)
	{
		for (int i = 0; i < row; i++)
			mas[i][j] = mas[i][j + 1];
	}
	(*col)--;
	for (int i = 0; i < row; i++)
		mas[i] = (int*)realloc(mas[i], *col * sizeof(int));
}
void delete_element_under_diagonal(int** mas, int col, int row)
{
	for (int i = 1; i < row; i++)
		mas[i] = (int*)realloc(mas[i], (col - i) * sizeof(int));
}

void print_row(int* col, int row)
{
	for (int i = 0; i < row; i++)
		printf("%4d", *(col + i));
	printf("\n");
}
void print_matr(int** matr, int row, int col)
{
	for (int i = 0; i < row; i++)
		print_row(matr[i], col);
}
void print_1mas(int** mas, int row, int* col)
{
	for (int i = 0; i < row; i++)
	{
		int fl = 0;
		for (int j = 0; j < col[i]; j++)
		{
			printf("%4d ", mas[i][j]);
		    fl = 1;
	    }
		if (fl) printf("\n");
	}
}
void print_3matr(int** mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - i; j++)
		{
			printf("%4d", mas[i][j]);
		}
		printf("\n");
	}
}



task1() 
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int** mas;
	int* col;
	int row = 0;

	printf("\nInput number of rows: ");
	row = numberOFrows(row);

	mas = (int**)malloc(row * sizeof(int*));
	col = (int*)malloc(row * sizeof(int));

	printf("\n");
	input_1mas(mas, row, col);
	system("cls");

	printf("Your matrix:\n\n");
	print_1mas(mas, row, col);

	printf("\nMatrix after changes:\n");
	delete_two_digit_numbers(mas, row, col);
	print_1mas(mas, row, col);

	for (int i = 0; i < row; i++)
	{
		free(mas[i]);
	}
	free(mas);
	free(col);
}

task2()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int** mas;
	int row = 0, col = 0, j = 0, choose = 0;

	printf("\nInput number of rows: ");
	row = numberOFrows(row);
	printf("Input number of columns: ");
	col = numberOFcolumns(col);

	memory(&mas, row, col);

	printf("\n");
	printf("\nInput next number:\n1 - Your array\n2 - Random array\n");
	printf("Your answer: ");
	choose = chooseINPUT(choose);

	input_matr(mas, row, col, choose, j);
	system("cls");

	printf("  Your matrix:\n\n");
	print_matr(mas, row, col);

	int deleted_col = col_with_biggestSUM(mas, row, col);
	printf("\nColumn with the biggest sum is %d\n", deleted_col+1);

	printf("\n  Matrix after changes:\n\n");
	delete_col_with_biggestSUM(mas, &col, row, deleted_col);
	print_matr(mas, row, col);
	printf("\n");

	for (int i = 0; i < row; i++)  
		free(mas[i]);              
	free(mas);
}

task3()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int** mas;
	int row = 0, col = 0, j = 0, choose = 0;

	printf("\nInput number of rows: ");
	row = numberOFrows(row);
	printf("Input number of columns: ");
	col = numberOFcolumns(col);

	memory(&mas, row, col);

	printf("\n");
	printf("\nInput next number:\n1 - Your array\n2 - Random array\n");
	printf("Your answer: ");
	choose = chooseINPUT(choose);

	input_matr(mas, row, col, choose, j);
	system("cls");

	printf("  Your matrix:\n\n");
	print_matr(mas, row, col);

	printf("\n  Matrix after changes:\n\n");
	delete_element_under_diagonal(mas, col, row);
	print_3matr(mas, row, col);
	printf("\n");

	for (int i = 0; i < row; i++)  
		free(mas[i]);            
	free(mas);
}








