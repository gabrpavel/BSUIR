int numberOFrows(int row);
int numberOFcolumns(int col);
int chooseINPUT(int choose);

void memory(int*** mas, int row, int col);
void memory_allocation(int** mas, int size);

void random_row(int* mas, int col);
void your_row(int* mas, int col, int j);

void input_row(int* mas, int col, int choose, int j);
void input_matr(int** mas, int row, int col, int choose, int j);

void print_row(int* col, int row);
void print_matr(int** matr, int row, int col);


//1 task
int positive_elements(int* mas, int size, int size1);
void copy_positive_mas(int* mas, int* copying_mas, int size);
void return_mas(int* mas, int* copying_mas, int size);
void copying_mass(int* mas, int* copying_mas, int size);
void returnCoped(int* mas, int* copying_mas, int size);

void merging(int* mas, int* mas1, int left, int mid, int right);
void mergeSort(int* mas, int* mas1, int left, int right);
void swap(int* elem1, int* elem2);
void SelectionSort(int* array, int len);


//2 task
int number_of_duplicate_elements_in_COL(int** mas, int row, int current_colum);
int duplicate(int** mas, int row, int col);
void selectionSort(int** mas, int row, int col);


task1();

task2();