#include "header.h"


Film* memory(int size) {

    Film* films;
    films = malloc(size*sizeof(Film));
    return films;

}
void free_memory(Film* film, int size) {

    for (int i = 0; i < size; ++i) {
        free(film[i].name);
        free(film[i].genre);
    }
    free(film);

}

int menu() {

    int choose;
    printf("Choose number of operation: \n");
    printf("\n1. Create new array of struct\n");
    printf("2. Show array of struct\n");
    printf("3. Delete struct\n");
    printf("4. Sort array of struct\n");
    printf("5. Add film\n");
    printf("6. End the program\n");
    printf("\nYour answer: ");
    while (scanf_s("%d", &choose) != 1 || choose < 1 || choose > 6 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    system("cls");
    return choose;
}

int get_size(int size) {

    printf("Enter number of films: ");
    while (scanf_s("%d", &size) != 1 || getchar() != '\n' || size < 1 )
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    system("cls");
    return size;
}
char* get_str() {
    int length = 1;
    char* string = (char*)malloc(length * sizeof(char));
    for (int i = 0;;i++){
        string[i] = (char)getchar();
        if (string[i] == '\n'){
            string[i] = '\0';
            break;
        }
        length++;
        string = (char*) realloc(string, length);
    }
    return string;
}
void create_film(Film* films, int i) {

    printf("Film [%d] name: ", i+1);
    films->name = get_str();

    printf("Film [%d] genre: ", i+1);
    films->genre = get_str();

    printf("Film [%d] review: ", i+1);
    while (scanf_s("%f", &films->review) != 1 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }

    printf("Film [%d] status: \n", i+1);
    printf("1. Viewed\n");
    printf("2. Not viewed\n");

    printf("Your answer: ");
    while (scanf_s("%d", &films->status) != 1 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    films->status --;

}
void create_mas_struct(Film* films, int size) {

    for (int i = 0; i < size; i++) {
        create_film(&films[i], i);
        printf("\n");
    }

    system("cls");
}

void show_film(const Film* film) {

    printf("Name: ");
    puts(film->name);
    printf("Genre: ");
    puts(film->genre);
    printf("Review: %.1f\n", film->review);
    printf("Status: ");
    puts(status[film->status]);

}
void show_mas_struct(const Film* films, int size) {

    for (int i = 0; i < size; ++i) {
        printf("Film [%d]\n", i+1);
        show_film(&films[i]);
        printf("\n");
    }
    getchar();
    system("cls");
}

Film* delete_struct(Film* films, int size) {
    printf("Choose the number of the Film that you want to delete\n\n");
    for (int i = 0; i < size; ++i) {
        printf("%d film: %s\n", i + 1, films[i].name);
    }
    printf("\nYour answer: ");

    int choose;
    while (scanf("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose > size) {
        printf("Error! Try again: ");
        rewind(stdin);
    }

    choose--;  // Decrement choose to match array indexing

    if (choose == size - 1) {
        size--;  // Decrease the size of the array
    }
    else {
        for (int i = choose; i < size - 1; ++i) {
            films[i] = films[i + 1];
        }
        size--;  // Decrease the size of the array
    }

    if (size > 0) {
        Film* resized_films = realloc(films, size * sizeof(Film));
        if (resized_films == NULL) {
            // Error handling for realloc failure
            printf("Error: Memory reallocation failed.\n");
            return films;  // Return the original array
        }
        else {
            films = resized_films;
        }
    }
    else {
        free(films);  // No need to reallocate, just free the memory
        films = NULL;
    }

    system("cls");

    return films;
}

void swap(Film* films, int j) {

    Film tmp = films[j];
    films[j] = films[j + 1];
    films[j + 1] = tmp;

}
void sort_mas_struct(Film* films, int size) {

    printf("Choose type of sort: \n");
    printf("\n1. Sort by review\n");
    printf("2. Sort by name\n");
    printf("3. Sort by genre\n");
    printf("4. Sort by review and name\n");
    printf("5. Sort by review and genre\n");
    printf("6. Sort by genre and name\n");

    printf("\nYour answer: ");
    int choose;
    while (scanf_s("%d", &choose) != 1 || choose < 1 || choose > 6 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    system("cls");

    switch (choose) {
        case 1:
            sort_review(films, size);
            break;
        case 2:
            sort_name(films, size);
            break;
        case 3:
            sort_genre(films, size);
            break;
        case 4:
            sort_review_name(films, size);
            break;
        case 5:
            sort_review_genre(films, size);
            break;
        case 6:
            sort_genre_name(films, size);
            break;
        default:
            break;
    }
}
void sort_name(Film* films, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if(strcmp(films[j].name, films[j+1].name) > 0)
                swap(films, j);

        }
    }

}
void sort_review(Film* films, int size) {


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if (films[j].review < films[j+1].review)
                swap(films, j);

        }
    }
}
void sort_genre(Film* films, int size) {


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if(strcmp(films[j].genre, films[j+1].genre) > 0)
                swap(films, j);

        }
    }
}
void sort_review_name(Film* films, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if (films[j].review < films[j+1].review)
                swap(films, j);
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if (films[j].review == films[j+1].review && strcmp(films[j].name, films[j+1].name) > 0)
                swap(films, j);

        }
    }

}
void sort_review_genre(Film* films, int size) {


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if (films[j].review < films[j+1].review)
                swap(films, j);

        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if (films[j].review == films[j+1].review && strcmp(films[j].genre, films[j+1].genre) > 0)
             swap(films, j);

        }
    }
}
void sort_genre_name(Film* films, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if(strcmp(films[j].genre, films[j+1].genre) > 0)
                swap(films, j);

        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {

            if (strcmp(films[j].genre, films[j+1].genre) == 0 && strcmp(films[j].name, films[j+1].name) > 0)
                    swap(films, j);
        }
    }

}