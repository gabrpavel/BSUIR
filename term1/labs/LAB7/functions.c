#include "header.h"

void reccurence(int* reset)
{
	printf("\nDo you want to continue? (yes - 1, no - 0)\n");
	printf("Your answer: ");
	while (scanf_s("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	system("cls");
}
void choose_task(int* choice)
{
	printf("Choose number of task:\n1. Input a string. Replace k-world with m-world\n2. Input strings S and S0. Find number of occurrences of string S0 in string S.\nYour choice: ");
	while (scanf_s("%d", choice) != 1 || *choice != 1 && *choice != 2 || getchar() != '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	system("cls");
}


int str_len(char** str)
{
	int i = 0;
	while (*(*str + i) != '\0')
		i++;
	return i;
}
void print(char** str)
{
	for (int i = 0; *(*str + i) != '\0'; i++)
		printf("%c", *(*str + i));
	printf("\n");
}


int if_letter(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) return 1;
	else return 0;
}
void getStr(char** str, int len)
{
	int c, i = 0;
	while ((c = getchar()) != EOF && c != '\n')
	{
		*(*str + i) = c;
		i++;
		len++;
		*str = (char*)realloc(*str, len);

	}
	*(*str + i) = '\0';
}

//task1
int input_N(int N)
{
	while (scanf_s("%d", &N) != 1 || getchar() != '\n' || N < 1)
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	return N;
}
int find_inputed_word(char** str, int N)
{
	int i = 0, cnt = 0;
	while ((*(*str + i) != '\0'))
	{
		if ((i == 0 && if_letter(*(*str + i)) == 1) || (if_letter(*(*str + i - 1)) == 0 && if_letter(*(*str + i)) == 1))
			cnt++;
		if (cnt == N)
			return i;
		i++;
	}
	return -1;
}
void reverse_str(char** str, int begin, int end)
{
	int temp = 0;
	int end1 = end;

	for (int k = begin, m = end1; k < m; k++, m--)
	{
		temp = *(*str + k);
		*(*str + k) = *(*str + m);
		*(*str + m) = temp;
	}
}
int end_of_word(char** str, int begin)
{
	while (if_letter(*(*str + begin)))
		begin++;
	return begin - 1;
}
void reverse_word(char** str, int begin)
{
	int temp = 0, end = 0;
	end = end_of_word(str, begin);
	for (int i = begin, j = end; i <= j; i++, j--)
	{
		temp = *(*str + i);
		*(*str + i) = *(*str + j);
		*(*str + j) = temp;
	}
}
void if_k_lower()
{

}
void if_k_higher()
{

}
//task2
int count_of_occurences(char** s, char** s0)
{
	int flag = 0, cnt = 0;

	for (int i = 0; *(*s + i) != '\0'; i++)
	{
		for (int j = 0; *(*s0 + j) != '\0'; j++)
		{
			if (*(*s + i + j) == *(*s0 + j))
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag) cnt++;
	}


	return cnt;
}


task1()
{
	char** str = (char**)malloc(sizeof(char*));
	*str = (char*)malloc(sizeof(char));

	int len = 1;
	int k = 0, m = 0;
	printf("Input string:\n");
	getStr(str, len);

	len = str_len(str);

	printf("\nInput k: ");
	k = input_N(k);
	printf("\nInput m: ");
	m = input_N(m);

	int begin = 0, end = 0;
	if (k < m)
	{
		begin = find_inputed_word(str, k);
		end = end_of_word(str, find_inputed_word(str, m));

		reverse_str(str, begin, end);
		print(str);

		reverse_word(str, begin);
		print(str);

		end = find_inputed_word(str, m);
		reverse_word(str, end);
		print(str);

		int begin1 = 0, end1 = 0;
		//begin1 = find_inputed_word(str, k + 1);
		//end1   = find_inputed_word(str, m - 1);
		begin1 = end_of_word(str, find_inputed_word(str, k)) + 1;
		end1 = find_inputed_word(str, m) - 1;
		reverse_str(str, begin1, end1);
		print(str);
	}
	else
	{
		end = end_of_word(str, find_inputed_word(str, k));
		begin = find_inputed_word(str, m);

		reverse_str(str, begin, end);
		print(str);

		reverse_word(str, begin);
		print(str);

		end = find_inputed_word(str, k);
		reverse_word(str, end);
		print(str);

		int begin1 = 0, end1 = 0;
		begin1 = end_of_word(str, find_inputed_word(str, m)) + 1;
		end1 = find_inputed_word(str, k) - 1;
		reverse_str(str, begin1, end1);
		print(str);
	}

}


task2()
{
	char** str = (char**)malloc(sizeof(char*));
	*str = (char*)malloc(sizeof(char));

	int length1 = 1;
	printf("Input s:\n");
	getStr(str, length1);

	char** str0 = (char**)malloc(sizeof(char*));
	*str0 = (char*)malloc(sizeof(char));

	int length2 = 1;
	printf("\nInput s0:\n");
	getStr(str0, length2);

	int count_of_occurences_s0_in_s = 0;
	count_of_occurences_s0_in_s = count_of_occurences(str, str0);
	if (count_of_occurences_s0_in_s == 0) printf("\nso isn't included in s\n");
	else printf("\nNumber of occurences s0 in s: %d\n", count_of_occurences_s0_in_s);

}