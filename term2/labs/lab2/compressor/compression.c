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
FILO* last(FILO* head) {

    if(head == NULL) return NULL;
    while(head->next) head = head->next;

    return head;
}
int compare(FILO* head, char* word) {

    while(head) {
        if(strcmp(head->word, word) == 0) return 1;
        head = head->next;
    }
    return 0;

}
void push(FILO** head, char* word, int repeat) {

    FILO* tail = last(*head);
    FILO* temp = (FILO*)malloc(sizeof(FILO));

    temp->word = word;
    temp->length = strlen(word);
    temp->repeat = repeat;
    temp->flag = 0;
    temp->next = NULL;

    if(*head == NULL) {
        *head = temp;
        return;
    }

    tail->next = temp;

}
void swap(string* text, char* first, char* second) {

    for (int i = 0; i < text->length; ++i) {

        if(strcmp(text->string[i], first) == 0) text->string[i] = second;
        else if(strcmp(text->string[i], second) == 0) text->string[i] = first;

    }

}
void split_FILO(FILO* head, FILO** first, FILO** last) {

    FILO* tmp1 = NULL;
    FILO* tmp2 = NULL;

    if(head == NULL || head->next == NULL) {
        (*first) = head;
        (*last)  = NULL;
        return;
    }

    tmp2 = head;
    tmp1 = head->next;

    while (tmp1!=NULL) {
        tmp1 = tmp1->next;
        if(tmp1!=NULL) {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    (*first) = head;
    (*last) = tmp2->next;
    tmp2->next = NULL;

}
void merging(FILO *a, FILO *b, FILO **c) {

    FILO tmp;
    *c = NULL;
    if (a == NULL) {
        *c = b;
        return;
    }
    if (b == NULL) {
        *c = a;
        return;
    }
    if (a->repeat * a->length > b->repeat * b->length) {
        *c = a;
        a = a->next;
    } else {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) {
        if (a->repeat * a->length > b->repeat * b->length) {
            (*c)->next = a;
            a = a->next;
        } else {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) {
        while (a) {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b) {
        while (b) {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;

}
void merge_sort(FILO** head) {

    FILO* first = NULL;
    FILO* last = NULL;

    if((*head == NULL) || ((*head)->next == NULL)) return;

    split_FILO(*head, &first, &last);
    merge_sort(&first);
    merge_sort(&last);
    merging(first, last, head);

}
void create_FILO(FILO** head, string* divided_text) {

    for (int i = 0; i < divided_text->length; i++) {

        if(compare(*head, divided_text->string[i])) continue;
        if(strstr(divided_text->string[i], "\n") != NULL) continue;

        int repeat = 0;
        for (int j = 0; j < divided_text->length; j++)
            if(strcmp(divided_text->string[i], divided_text->string[j]) == 0) repeat++;
        push(&(*head), divided_text->string[i], repeat);

    }

    merge_sort(&(*head));

}
void plant_flag(FILO* head, char* word) {

    while(head) {

        if(strcmp(head->word, word) == 0) {
            head->flag = 1;
            return;
        }

        head = head->next;

    }

}
int benefit(FILO* first, FILO* second) {

    if(first->repeat <= second->repeat) return 0;
    else if(first->flag || second->flag) return -1;

    else return (first->repeat*first->length + second->repeat*second->length) -
                (first->repeat*second->length + second->repeat*first->length) -
                (first->length + second->length + 2);

}
void replace(FILO* head, string* split_text)        {

    FILO* first = head;

    fclose(fopen("tools.txt", "w"));

    while(first) {

        int max = 0;
        char* word;
        FILO* second = head;

        while(second) {

            int catch = benefit(first, second);
            if(catch > max) {
                max = catch;
                word = second->word;
            }

            second = second->next;

        }
        if(max > 0) {

            plant_flag(head, first->word);
            plant_flag(head, word);

            if(strlen(word) == 0 || strlen(first->word) == 0) continue;
            swap(split_text, first->word, word);

            FILE* fptr = fopen("tools.txt", "ab");
            if(fptr == NULL) exit(0);

            fputs(first->word, fptr);
            fputs(" ", fptr);
            fputs(word, fptr);
            fputs("\n", fptr);
            fclose(fptr);

        }

        first = first->next;

    }

}


void compression(char file[]) {

    string* divided_text = read(file);

    if(divided_text == NULL) {
        printf("Error!\n");
        exit(1);
    }


    FILE* fptr = fopen(file, "rb");
    fseek(fptr, 0L, SEEK_END);
    long size = ftell(fptr);
    printf("Original size: %ld\n", size);

    printf("Processing...\n");

    FILO* head = NULL;

    create_FILO(&head, divided_text);
    replace(head,divided_text);

    fclose(fopen("compressed.txt", "w"));

    fclose(fptr);
    fptr = fopen("compressed.txt", "ab");
    if(fptr == NULL) exit(0);

    for (int i = 0; i < divided_text->length; ++i) {
        fputs(divided_text->string[i], fptr);
        if(i != divided_text->length - 1) fputs(" ", fptr);
    }

    fseek(fptr, 0L, SEEK_END);
    size = ftell(fptr);
    printf("Reduced size: %ld\n", size);

    fclose(fptr);
    fptr = fopen("tools.txt", "rb");
    fseek(fptr, 0L, SEEK_END);
    long tools_size = ftell(fptr);
    fclose(fptr);

    printf("Tools size: %ld\n", tools_size);
    printf("Full size: %ld\n", size + tools_size);
    printf("File compressed!!!\n");



     for (int i = 0; divided_text->string[i] != NULL; ++i) {
         free(divided_text->string[i]);
    }

    free(divided_text->string);
    free(divided_text);

}