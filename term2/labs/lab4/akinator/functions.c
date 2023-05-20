#include "header.h"


char* get_str() {

    int length = 1;
    char* string = (char *) malloc(length * sizeof(char));
    for (int i = 0;; i++) {
        string[i] = (char) getchar();
        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }
        length++;
        string = (char *) realloc(string, length);
    }

    return string;

}

Node *create_node(char *input) {

    Node *node = (Node *) malloc(sizeof(Node));

    node->question = _strdup(input);
    node->yes = NULL;
    node->no = NULL;

    return node;

}

void akinator(Node *node) {

    printf("Answer the questions below to get prediction.\n\n");
    printf("If you want to exit, input 1\n\n");
    printf("%s\n", node->question);

    char *answer = get_str();
    while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0 && strcmp(answer, "1") != 0) {
        printf("Input \"yes\" or \"no\"\n");
        rewind(stdin);
        answer = get_str();
    }
    system("cls");

    if(strcmp(answer, "1") == 0) {
        free(answer);
    }
    else if (strcmp(answer, "yes") == 0) {

        if (node->yes == NULL) {

            printf("Hooray, I guessed it! :)\n");
            free(answer);
            system("pause");

        } else {
            free(answer);
            akinator(node->yes);
        }

    } else {

        free(answer);

        if (node->no == NULL) {


            printf("Sorry, I can't guess...\nWho is your person?\n");
            char *new_object = get_str();

            printf("What is a question that distinguishes %s from %s?\n", new_object, node->question);
            char *new_question = get_str();
            new_question = realloc(new_question, strlen(new_question) + 1);
            strcat(new_question, "\n");

            printf("What is the answer to the question for %s?\n", new_object);
            char *new_answer = get_str();

            Node *new_node = create_node(new_question);
            free(new_question);


            new_object = realloc(new_object, strlen(new_object) + 1);
            strcat(new_object, "\n");

            if (strcmp(new_answer, "yes") == 0) {

                new_node->yes = create_node(new_object);
                new_node->no = create_node(node->question);
                free(new_object);

            } else {

                new_node->yes = create_node(node->question);
                new_node->no = create_node(new_object);
                free(new_object);

            }

            free(new_answer);
            memcpy(node, new_node, sizeof(Node));
            free(new_node);

        } else akinator(node->no);
    }


}

void get_leaf_elements(const Node* root, Leafs* leafs) {

    if(root == NULL) return;

    if(root->no == NULL && root->yes == NULL) {
        leafs->element = realloc(leafs->element, (leafs->count+1)*sizeof(char*));
        leafs->element[leafs->count++] = _strdup(root->question);
    }
    else {
        get_leaf_elements(root->yes, leafs);
        get_leaf_elements(root->no, leafs);
    }

}

void remember_path(const Node* root, char* key, Path* path, int* len) {

    if(root == NULL) *len = 0;
    else if(strcmp(root->question, key) == 0 && root->yes == NULL && root->no == NULL) {

        path->count = *len;
        path->question = realloc(path->question, (path->count+1)*sizeof(char*));
        path->answer = realloc(path->answer, (path->count+1)*sizeof(char*));

        path->question[path->count] = _strdup(root->question);
        path->answer[path->count] = _strdup("yes");
        (*len)++;

    }
    else {
        remember_path(root->no, key, path, len);
        if(*len > 0) {

            path->count = *len;
            path->question = realloc(path->question, (path->count+1)*sizeof(char*));
            path->answer = realloc(path->answer, (path->count+1)*sizeof(char*));

            path->question[path->count] = _strdup(root->question);
            path->answer[path->count] = _strdup("no");
            (*len)++;

        }
        else {
            remember_path(root->yes, key, path, len);
            if(*len > 0) {

                path->count = *len;
                path->question = realloc(path->question, (path->count+1)*sizeof(char*));
                path->answer = realloc(path->answer, (path->count+1)*sizeof(char*));

                path->question[path->count] = _strdup(root->question);
                path->answer[path->count] = _strdup("yes");

                (*len)++;

            }
        }
    }

}

void reverse_akinator(const Node *node) {

    Leafs* leafs = malloc(sizeof(Leafs));
    leafs->element = (char**)malloc(sizeof(char*));
    leafs->count = 0;

    get_leaf_elements(node, leafs);

    int num_enigma;
    if (leafs->count == 0) {
        printf("I can't make a wish (\n");
        return;
    }
    else num_enigma = rand() % (leafs->count);


    Path* path = malloc(sizeof(Path));
    int size = 0;
    path->count = 0;
    path->question = (char**)malloc(sizeof(char*));
    path->answer = (char**)malloc(sizeof(char*));
    char* enigma = _strdup(leafs->element[num_enigma]);

    for(int i = leafs->count-1; i >= 0; i--) free(leafs->element[i]);
    free(leafs->element);
    free(leafs);

    remember_path(node, enigma, path, &size);

    printf("Ask questions, I will answer \"yes\", \"no\" or \"I don't know\"\n\n"
           "If you GIVE UP and want to see the answer, input 1\n");

    while(1) {

        printf("Your question: ");
        char* question = get_str();
        question = realloc(question, strlen(question) + 2);
        strcat(question, "\n");

        if(strcmp(question, "1\n") == 0) {
            system("cls");
            printf("You're a weakness\n"
                   "I made a wish for %s", enigma);
            system("pause");
            break;
        }
        else if(strcmp(question, enigma) == 0) {

            system("cls");
            printf("Congrats, you win!\n");
            free(question);
            system("pause");

            break;

        }
        else {
            int flag = 0;

            for (int i = 0; i < size; i++) {


                if(strcmp(question, path->question[i]) == 0) {
                    printf("My answer: %s\n", path->answer[i]);
                    flag = 1;
                }


            }
            if(flag == 0) printf("I don't know :(\n");

            free(question);

        }

   }

    for(int i = 0; i < size ; i++) free(path->answer[i]);
    for(int i = 0; i < size ; i++) free(path->question[i]);
    free(path->answer);
    free(path->question);
    free(path);
    free(enigma);


}

void free_tree(Node *node) {

    if (node != NULL) {
        if(node->no != NULL) free_tree(node->no);
        if(node->yes != NULL) free_tree(node->yes);
        free(node);
    }

}

Node* read(FILE *file) {

    char question[100];
    fgets(question, sizeof(question), file);
    if (question[0] == '#') return NULL;

    Node *node = create_node(question);
    node->yes = read(file);
    node->no = read(file);

    return node;

}

void save_tree(Node *node, FILE *file) {

    if (node == NULL) {

        fprintf(file, "#\n");
        return;

    }

    fprintf(file, "%s", node->question);
    save_tree(node->yes, file);
    save_tree(node->no, file);

}

int cycle() {

    int choose;

    system("cls");

    printf("0. Exit\n");
    printf("1. Akinator\n");
    printf("2. Reverse Akinator\n");
    printf("3. Show base\n");
    printf("Your answer: ");

    while (scanf_s("%d", &choose) != 1 || choose < 0 || choose > 3 || getchar() != '\n') {
        printf("Error! Try again...\n");
        rewind(stdin);
    }
    system("cls");

    return choose;

}