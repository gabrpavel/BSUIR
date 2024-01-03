#include "header.h"


void print(char** mas, int str_cnt)
{
	for (int i = 0; i < str_cnt; i++)
		printf("%s\n", *(mas + i));
}
int Len(char** mas, int str_pos)
{
	int cnt = 0, i = 0;
	while (*(*(mas + str_pos) + i) != '\0')
	{
		cnt++;
		i++;
	}
	return cnt + 1;
}

int get_words_of_even(char* line)
{
    int words = 0, start = 0;
    for (int i = len(line); i != 0; i--)
    {
        if (is_letter(line[i - 1]) && !is_letter(line[i]))
        {
            start = i;
            continue;
        }
        if (!is_letter(line[i - 1]) && is_letter(line[i]))
        {
            words += ((start - i) % 2 == 0);
            start = 0;
        }
    }
    if (is_letter(line[0]) && start != 0)
        words += (start % 2 == 0);
    return words;
}
void swap(char** line1, char** line2) {
    char* temp = *line1;
    *line1 = *line2;
    *line2 = temp;
}


void QuickSort(char** mas, int size)
{
    char* mas1;
    for (int i = 1; i < size; i++)
    {
        int start = i;
        int end = i;
        while (get_words_of_even(*(mas + end)) < get_words_of_even(*(mas + start - 1)))
        {
            if (start - 1 == 0)
            {
                start--;
                break;
            }
            start--;
        }
        mas1 = *(mas + end);
        while (end > start)
        {
            *(mas + end) = *(mas + end - 1);
            end--;
        }
        *(mas + start) = mas1;
    }
}
void copy_argv_to_mas(char** mas, char** new_mas, int str_cnt)
{
    for (int i = 0; i < str_cnt; i++)
        for (int j = 0; j < Len(mas, i); j++)
            *(*(new_mas + i) + j) = *(*(mas + i) + j);
}
void delete_adress(char** mas, int str_cnt)
{
    for (int i = 0; i < str_cnt - 1; i++)
        *(mas + i) = *(mas + i + 1);
}





int is_letter(char line) {
    if ((line >= 'a' && line <= 'z') || (line >= 'A' && line <= 'Z'))
        return 1;
    return 0;
}
int len(char* line) {
    int i = 0;
    for (; line[i] != '\0'; i++);
    return i;
}







