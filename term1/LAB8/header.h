#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print(char** mas, int str_cnt);
int Len(char** s, int str_pos);

void copy_argv_to_mas(char** mas, char** new_mas, int str_cnt);
void delete_adress(char** mas, int str_cnt);
void QuickSort(char** mas, int size);


int is_letter(char line);
int len(char* line);
int get_words_of_even(char* line);
void swap(char** line1, char** line2);
