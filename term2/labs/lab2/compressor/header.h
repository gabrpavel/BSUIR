#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct FILO {

    char* word;
    int length;
    int repeat;
    int flag;
    struct FILO *next;

} FILO;

typedef struct string {

    char** string;
    int length;

} string;

void compression(char file[]);
