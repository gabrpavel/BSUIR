#include "header.h"

string* read(char file[]) {

    FILE* fp = fopen(file, "r");
    if(fp == NULL) {
        printf("File not found.\n");
        return 0;
    }

    string* str = malloc(sizeof(string));
    str->length = 0;
    str->string = NULL;

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* string = calloc(length, 1);

    fread(string, 1, length,fp);
    fclose(fp);

    char seps[] = " ";
    char* token = strtok(string, seps);
    while(token != NULL)
    {
        str->string = realloc(str->string, (str->length+1)*sizeof(char*));
        str->string[str->length++] = token;
        token = strtok(NULL, seps);
    }

    free(string);
    free(token);
    return str;
}
void swap(string* text, char* first, char* second) {

    for (int i = 0; i < text->length; ++i) {

        if(strcmp(text->string[i], first) == 0) text->string[i] = second;
        else if(strcmp(text->string[i], second) == 0) text->string[i] = first;

    }

}
string* divide_text_into_words(char* text) {

    string* str = malloc(sizeof(string));
    str->length = 0;
    str->string = NULL;

    char seps[] = " ";
    char* token = strtok(text, seps);

    while(token != NULL) {

        str->string = realloc(str->string, (str->length+1)*sizeof(char*));
        str->string[str->length++] = token;

        token = strtok(NULL, seps);

    }

    free(token);

    return str;
}
string* split_text_into_strings(char file[]) {

    FILE* fp = fopen(file, "r");
    if(fp == NULL) {
        printf("File not found.\n");
        return 0;
    }

    string* str = malloc(sizeof(string));
    str->length = 0;
    str->string = NULL;

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* text = calloc(length, 1);

    fread(text, 1, length,fp);
    fclose(fp);

    char seps[] = "\n";
    char* token = strtok(text, seps);

    while(token != NULL) {

        str->string = realloc(str->string, (str->length+1)*sizeof(char*));
        str->string[str->length++] = token;

        token = strtok(NULL, seps);

    }

    free(text);
    free(token);

    return str;
}
void decompression() {

    string* compressed_text = read("compressed.txt");
    if(compressed_text == NULL) exit(0);

    FILE* fptr = fopen("compressed.txt", "rb");
    fseek(fptr, 0L, SEEK_END);
    long size = ftell(fptr);
    printf("Compressed size: %ld\n", size);

    fclose(fptr);


    string* compressed_tools = split_text_into_strings("tools.txt");
    if(compressed_tools == NULL) exit(0);

    fptr = fopen("tools.txt", "rb");
    fseek(fptr, 0L, SEEK_END);
    long tools_size = ftell(fptr);
    printf("Tools size: %ld\n", tools_size);
    printf("Full size: %ld\n\n", size + tools_size);

    fclose(fptr);
    
    printf("Processing...\n\n");

    for (int i = 0; i < compressed_tools->length; ++i) {

        string* word = divide_text_into_words(compressed_tools->string[i]);
        if(word->length != 2) continue;
        swap(compressed_text, word->string[0], word->string[1]);
        free(word);

    }





    fclose(fopen("decompressed.txt", "w"));
    fptr = fopen("decompressed.txt","ab");

    if(fptr == NULL) exit(0);

    for (int i = 0; i < compressed_text->length; ++i) {

        fputs(compressed_text->string[i], fptr);
        if(i != compressed_text->length -1) fputs(" ", fptr);

    }

    fseek(fptr, 0L, SEEK_END);
    size = ftell(fptr);
    fclose(fptr);

    free(compressed_text);
    free(compressed_tools);

    printf("Decompressed size: %ld\n", size);
    printf("File decompressed!!!\n");
}