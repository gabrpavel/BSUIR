#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int numberOFrows(int row)
{
	while (scanf_s("%d", &row) != 1 || getchar() != '\n' || row < 1 )
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return row;
}
int numberOFcolumns(int col)
{
	while (scanf_s("%d", &col) != 1 || getchar() != '\n' || col < 1 )
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
void memory_allocation(int** mas, int size)
{
	*mas = (int*)malloc(size * sizeof(int));
}

void random_row(int* mas, int col)
{
	for (int i = 0; i < col; i++)
		mas[i] = (rand() % 50) - 25;
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
			continue;
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
		input_row(*(mas + i), col, choose, j);
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


//1 task
int positive_elements(int* mas, int size, int size1) {

	for (int i = 0; i < size; i++)
	{
		if (mas[i] > 0)
			size1++;
	}
	return size1;
}
void copy_positive_mas(int* mas, int* copying_mas, int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > 0)
		{
			copying_mas[j] = mas[i];
			j++;
		}
	}
}
void return_mas(int* mas, int* copying_mas, int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > 0)
		{
			mas[i] = copying_mas[j];
			j++;
		}
	}
}
void copying_mass(int* mas, int* copying_mas, int size)
{
	int  j = 0;
	for (int i = 0; i < size; i++)
	{
		copying_mas[j] = mas[i];
		j++;
	}
}
void returnCoped(int* mas, int* copying_mas, int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		mas[i] = copying_mas[j];
		j++;
	}
}

void merging(int* mas, int* mas1, int left, int mid, int right) {
	mid = (left + right) / 2;
	int l1 = 0, l2 = 0, i = 0;

	for (l1 = left, l2 = mid + 1, i = left; l1 <= mid && l2 <= right; i++) {

		if (mas[l1] <= mas[l2]) {
			mas1[i] = mas[l1++];
		}
		else {
			mas1[i] = mas[l2++];
		}
	}
	while (l1 <= mid) {

		mas1[i] = mas[l1];
		i++;
		l1++;
	}
	while (l2 <= right) {
		mas1[i] = mas[l2];
		i++;
		l2++;
	}

	for (i = left; i <= right; i++) {

		mas[i] = mas1[i];

	}
}
void mergeSort(int* mas, int* mas1, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(mas, mas1, left, mid);
		mergeSort(mas, mas1, mid + 1, right);
		merging(mas, mas1, left, mid, right);
	}
}
void swap(int* elem1, int* elem2)
{
	int tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

void SelectionSort(int* array, int len) {

	for (int i = 0; i < len; i++) {
		if (array[i] > 0) {
			for (int k = i + 1; k < len; k++) {
				if (array[k] > 0) {
					if (array[i] > array[k])
					{
						swap(&array[i], &array[k]);
					}
				}
			}
		}
	}
}


//2 task
int number_of_duplicate_elements_in_COL(int** mas, int row, int current_colum)
{
	int number_of_duplicate_elements = 0;
	for (int i = 0; i < row; i++)
	{
		for (int k = (i + 1); k < row; k++)
		{
			if (mas[k][current_colum] == mas[i][current_colum])
			{
				number_of_duplicate_elements++;
				for (int j = (i - 1); j >= 0; j--)
				{
					if (mas[j][current_colum] == mas[i][current_colum])
					{
						number_of_duplicate_elements--;
						break;
					}
				}
				break;
			}
		}
	}
	return number_of_duplicate_elements;
}
int duplicate(int** mas, int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		int number_of_duplicate_elements = number_of_duplicate_elements_in_COL(mas, row, i);
		printf("%4d", number_of_duplicate_elements);
	}
}
void selectionSort(int** mas, int row, int col)
{
	int tmp, pos;
	for (int i = 0; i < col; i++)
	{
		pos = number_of_duplicate_elements_in_COL(mas, row, i);
		for (int j = i + 1; j < col; j++)
		{
			if (pos < number_of_duplicate_elements_in_COL(mas, row, j))
			{
				pos = number_of_duplicate_elements_in_COL(mas, row, j);
				for (int r = 0; r < row; r++)
				{
					for (int c = i; c < col; c++)
					{
						tmp = mas[r][c];
						mas[r][c] = mas[r][j];
						mas[r][j] = tmp;
					}
				}
			}
		}

	}
}







task1() 
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	
	int* mas = NULL;
	int* mas1 = NULL;
	int* positive_arr = NULL;
	int* additional_arr = NULL;

	int size = 0, positive = 0, choose = 0, j = 0;
	double start = 0, end = 0;
	double end1 = 0, start1 = 0;

	printf("Input number of elements\n");
	size = numberOFrows(size);

	memory_allocation(&mas, size);

	printf("\nInput next number:\n1 - Your array\n2 - Random array\n");
	printf("Your answer: ");
	choose = chooseINPUT(choose);

	input_row(mas, size, choose, j);
	system("cls");

	memory_allocation(&mas1, size);

	copying_mass(mas, mas1, size);
	printf("  Your array:\n\n");
	print_row(mas, size);
	printf("\n");

	memory_allocation(&additional_arr, size);
	copying_mass(mas, additional_arr, size);

	positive = positive_elements(mas, size, positive);
	memory_allocation(&positive_arr, positive);
	copy_positive_mas(mas, positive_arr, size);
	 //MERG SORT
	start = clock();
	mergeSort(positive_arr, mas1, 0, positive - 1);
	end = clock();
	
	return_mas(mas, positive_arr, size);

	printf("\n  Array after sort:\n\n");
	print_row(mas, size);
	printf("\n");

	printf("\nWhich sort is faster? (Merge or Selection)\n");
	//SELECTION SORT
	start1 = clock();
	SelectionSort(additional_arr, size);
	end1 = clock();

	printf("\nTime of MergeSort = %.4lf", (end - start));
	printf("\nTime of SelectionSort = %.4lf\n\n", (end1 - start1));


	return 0;
}

task2() //38
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

	printf("\n");
	duplicate(mas, row, col);
	printf("\n");

	printf("\n  Matrix after sort:\n\n");
	selectionSort(mas, row, col);
	print_matr(mas, row, col);
	printf("\n");

	duplicate(mas, row, col);
	printf("\n");
}
