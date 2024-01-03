#include "header.h"

void main(int argc, char** argv) 
{
    if (argc < 2)
    {
        printf("Too few arguments...");
        return 0;
    }

    char** mas = (char**)malloc((argc) * sizeof(char*)); 

    for (int i = 0; i < argc; i++)
        *(mas + i) = (char*)malloc(Len(argv, i) * sizeof(char));
	
    copy_argv_to_mas(argv, mas, argc);
    delete_adress(mas, argc);
    argc--;

    mas = (char**)realloc(mas, argc * (sizeof(char*)));

    printf("array before:\n");
    print(mas, argc);

    QuickSort(mas, argc);

    printf("\narray after:\n");
    print(mas, argc);
}