#include "header.h"


int menu() {

    int choose;

    printf("Choose an action: \n\n");
    printf("1. Find IP adress\n");
    printf("2. Find Domain\n");
    printf("3. Add to file\n");
    printf("4. Output cache\n");
    printf("5. Exit\n\n");
    printf("Your answer: ");

    while (scanf_s("%d", &choose) != 1 || choose < 1 || choose > 5 || getchar() != '\n') {

        printf("Error! Try again...\n");
        rewind(stdin);

    }

    system("cls");
    return choose;

}

char* get_str() {

    int length = 1;
    char* string = (char*)malloc(length * sizeof(char));
    for (int i = 0;; i++) {
        string[i] = (char)getchar();
        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }
        length++;
        string = (char*)realloc(string, length);
    }

    return string;

}

int validate_IP(const char* ip) {

    int num;
    int segments = 0;

    char* copy = _strdup(ip);

    char* token = strtok(copy, ".");
    while (token != NULL) {

        for (int i = 0; token[i] != '\0'; i++) {
            if (!isdigit(token[i])) {
                free(copy);
                return 0;
            }
        }

        num = atoi(token);


        if (num < 0 || num > 255) {
            free(copy);
            return 0;
        }

        token = strtok(NULL, ".");
        segments++;
    }


    if (segments != 4) {
        free(copy);
        return 0;
    }


    if (ip[strlen(ip) - 1] == '.') {
        free(copy);
        return 0;
    }

    free(copy);
    return 1;
}

char* file_reader(char path[]) {

    long len;

    FILE* fp = fopen(path, "r");
    if (fp == NULL) return NULL;

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = calloc(len, 1);

    fread(buffer, 1, len, fp);
    fclose(fp);

    return buffer;
}

String* divide_string(char* divisible, char* delimiter) {
    String* str = malloc(sizeof(String));
    char* copy = _strdup(divisible);
    str->str = NULL;
    str->size = 0;

    char* token = strtok(copy, delimiter);
    while (token != NULL) {
        str->str = realloc(str->str, (str->size + 1) * sizeof(char*));
        str->str[str->size++] = _strdup(token);
        token = strtok(NULL, delimiter);
    }

    free(copy);  
    return str;
}


/////////////////////////////////////////////////////////////////////////

Node* create_node(char* key, char* value) {

    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    node->collision = NULL;

    return node;

}

List* create_list(int capacity) {

    List* list = (List*)malloc(sizeof(List));

    list->size = 0;
    list->capacity = capacity;
    list->head = list->tail = NULL;

    return list;

}

Hash_Table* create_hash_table(int size) {

    Hash_Table* hash_table = (Hash_Table*)malloc(sizeof(Hash_Table));

    hash_table->capacity = size;
    hash_table->values = (Node**)malloc(sizeof(Node) * size);

    for (int i = 0; i < size; i++) hash_table->values[i] = NULL;

    return hash_table;

}

Cache* create_cache(int size) {

    Cache* cache = (Cache*)malloc(sizeof(Cache));
    Hash_Table* hash_table = create_hash_table(size * 2);
    List* list = create_list(size);

    cache->hash_table = hash_table;
    cache->list = list;

    return cache;

}

/////////////////////////////////////////////////////////////////////////

size_t get_hash_index(Hash_Table* hash_table, const char* str) {

    if (str == NULL) return 0;

    size_t hash = 0;
    int c;
    while ((c = *str++)) hash = (hash * 33) + c;

    return hash % hash_table->capacity;
}

void cache_correction(Cache* cache) {

    Hash_Table* table = cache->hash_table;
    List* list = cache->list;

    Node* entry = list->head;

    if (list->head == NULL) return;

    if (list->head == list->tail) {

        list->head = NULL;
        list->tail = NULL;

    }

    else {

        list->head = entry->next;
        list->size = list->size - 1;
        list->head->prev = NULL;

    }

    size_t index = get_hash_index(table, entry->key);
    Node** node = &table->values[index];

    while ((*node) != entry) node = &(*node)->next;
    *node = entry->next;

    free(entry);

}

void cache_shift(Cache* cache, char* key) {

    Hash_Table* table = cache->hash_table;
    List* list = cache->list;

    if (list->size == 1) return;

    size_t index = get_hash_index(table, key);
    Node* curr = table->values[index];

    while (curr) {

        if (strcmp(curr->key, key) == 0) break;
        curr = curr->collision;

    }

    if (curr == NULL) return;

    if (curr->prev == NULL) {

        curr->prev = list->tail;
        list->head = curr->next;
        list->head->prev = NULL;
        list->tail->next = curr;
        list->tail = curr;
        list->tail->next = NULL;
        return;

    }

    if (curr->next == NULL) return;

    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    curr->next = NULL;
    list->tail->next = curr;
    curr->prev = list->tail;
    list->tail = curr;

}

void add_to_list(Cache* cache, Node* node) {

    List* list = cache->list;

    if (list->size == list->capacity) cache_correction(cache);

    if (list->head == NULL) {

        list->head = list->tail = node;
        list->size = 1;
        return;

    }

    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
    list->size = list->size + 1;

}

int add_to_table(Hash_Table* hash_table, Node* node) {

    size_t index = get_hash_index(hash_table, node->key);

    if (hash_table->values[index] != NULL) {

        Node* curr = hash_table->values[index];

        while (curr->collision != NULL) {

            if (strcmp(curr->key, node->key) == 0) {

                curr->value = node->value;
                return 1;

            }

            curr = curr->collision;

        }

        if (strcmp(curr->key, node->key) == 0) {

            curr->value = node->value;
            return 1;

        }

        curr->collision = node;
        return 0;

    }

    else {

        hash_table->values[index] = node;
        return 0;

    }

}

void put(Cache* cache, char* key, char* value) {

    Node* node = create_node(key, value);

    if (add_to_table(cache->hash_table, node)) cache_shift(cache, node->key);
    else add_to_list(cache, node);

}

void cache_init(Cache* cache) {

    FILE* fptr = fopen("DNS.txt", "r");
    char buffer[BUFFER];
    int flag = 1;

    while (fgets(buffer, BUFFER, fptr)) {

        if (strcmp(buffer, "") == 0) break;
        if (flag > MAX_CACHE) break;
        flag++;

        String* result = divide_string(buffer, " ");
        result->str[3][strlen(result->str[3]) - 1] = '\0';
        put(cache, _strdup(result->str[0]), _strdup(result->str[3]));

    }

    fclose(fptr);

}

/////////////////////////////////////////////////////////////////////////

void get_in_file(char* key, Cache* cache) {

    printf("Searching %s in file\n", key);

    char buffer[BUFFER];
    FILE* fp = fopen("DNS.txt", "r");

    while (fgets(buffer, BUFFER, fp)) {

        String* record = divide_string(buffer, " ");

        if (strcmp(record->str[0], key) == 0) {

            record->str[3][strlen(record->str[3]) - 1] = '\0';
            put(cache, _strdup(record->str[0]), _strdup(record->str[3]));
            break;

        }

    }

    fclose(fp);

}

char* get(Cache* cache, const char* key) {

    Hash_Table* hash_table = cache->hash_table;
    size_t index = get_hash_index(hash_table, key);
    Node* curr = hash_table->values[index];

    while (curr) {

        if (strcmp(curr->key, key) == 0) {

            cache_shift(cache, key);
            return curr->value;

        }

        curr = curr->collision;

    }

    return NULL;

}

char* get_IP(Cache* cache, char* key) {

    char* record = get(cache, key);

    if (!record) {

        get_in_file(key, cache);
        record = get(cache, key);

        if (!record) return NULL;

    }

    if (validate_IP(record)) return record;
    else record = get_IP(cache, record);

    return record;

}

void find_IP(Cache* cache) {

    printf("Input domain: ");
    char* domain = get_str();

    char* IP = get_IP(cache, domain);
    if (IP) printf("IP: %s\n", IP);
    else printf("Domain doesn't exist!\n");

    system("pause");
    system("cls");

}

void find_domain(Cache* cache) {

    printf("Input IP: ");

    char* ip = get_str();

    char buffer[BUFFER];
    FILE* fp = fopen("DNS.txt", "r");

    while (fgets(buffer, BUFFER, fp)) {

        String* record = divide_string(buffer, " ");
        record->str[3][strlen(record->str[3]) - 1] = '\0';

        if (strcmp(record->str[3], ip) == 0) {

            printf("%s\n", record->str[0]);

            //rewind(fp);
            fclose(fp);
            fp = fopen("DNS.txt", "r");
            char buffer2[BUFFER];

            while (fgets(buffer2, BUFFER, fp)) {

                String* record2 = divide_string(buffer2, " ");
                record2->str[3][strlen(record2->str[3]) - 1] = '\0';
                if (strcmp(record2->str[3], record->str[0]) == 0) printf("%s\n", record2->str[0]);

            }

            break;

        }

    }

    fclose(fp);
    system("pause");
    system("cls");

}

void add_to_file() {
    printf("Input : ");

    char* record = get_str();

    String* split_record = divide_string(_strdup(record), " ");
    if (split_record->size != 4) {
        printf("Invalid count of arguments!\n");
        system("pause");
        system("cls");
        free(record);
        free(split_record);
        return;
    }

    if (!validate_IP(_strdup(split_record->str[3])) && !strstr(_strdup(record), "CNAME")) {
        printf("Error with IP!\n");
        system("pause");
        system("cls");
        free(record);
        free(split_record);
        return;
    }

    char* text = file_reader("DNS.txt");

    if (strstr(text, record)) {
        printf("Record already in file\n");
        system("pause");
        system("cls");
        free(text);
        free(record);
        free(split_record);
        return;
    }

    FILE* fp = fopen("DNS.txt", "a");
    if (fp == NULL) {
        free(text);
        free(split_record);
        free(record);  
        return;
    }

    fputs(record, fp);
    fputs("\n", fp);
    fclose(fp);
    free(text);
    free(split_record);
    free(record);  

    printf("Record added!\n");
    system("pause");
    system("cls");
}


void output_cache(Cache* cache) {

    Node* temp = cache->list->head;

    for (int i = cache->list->size - 1; i >= 0; i--) {

        printf("[%d] %s %s \n", i + 1, temp->key, temp->value);
        temp = temp->next;

    }

    system("pause");
    system("cls");

}

void free_memory(Cache* cache) {

    Hash_Table* table = cache->hash_table;
    List* list = cache->list;

    Node* tmp = list->head;

    while (tmp) {

        Node* next = tmp->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);

        tmp = next;

    }


    free(table->values);
    free(table);
    free(list);

    system("cls");

    printf("Clearing memory\n");

    system("pause");

}