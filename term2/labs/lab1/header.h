#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

static char* status[] = {
        "Viewed\0",
        "Not viewed\0",
};

typedef enum {
    VIEWED,
    NOT_VIEWED,
}Status;


typedef struct {
    char* name;
    char* genre;
    float review;
    Status status;
} Film;

char* get_str();
int menu();
Film* memory(int size);
int get_size(int size);
void show_film(const Film* film);
void show_mas_struct(const Film* films, int size);
void free_memory(Film* film, int size);
void create_mas_struct(Film* films, int size);


void swap(Film* films, int j);
void sort_mas_struct(Film* films, int size);

void sort_review(Film* films, int size);
void sort_name(Film* films, int size);
void sort_genre(Film* films, int size);
void sort_review_name(Film* films, int size);
void sort_review_genre(Film* films, int size);
void sort_genre_name(Film* films, int size);



Film* delete_struct(Film* films, int size);
void create_film(Film* films, int i);
