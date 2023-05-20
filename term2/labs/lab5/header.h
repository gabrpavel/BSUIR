#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_CACHE 5
#define BUFFER 256

typedef enum Menu {

	FIND_IP = 1,
	FIND_DOMAIN,
	ADD_TO_FILE,
	OUTPUT,
	EXIT

} Menu;

typedef struct String {

	int size;
	char** str;

} String;

typedef struct Node {

	char* key;
	char* value;

	struct Node* next;
	struct Node* prev;
	struct Node* collision;

} Node;

typedef struct Hash_Table {

	int capacity;
	Node** values;

} Hash_Table;

typedef struct List {

	int size;
	int capacity;

	Node* head;
	Node* tail;

} List;

typedef struct Cache {

	Hash_Table* hash_table;
	List* list;

} Cache;

int menu();

Cache* create_cache(int size);
void cache_init(Cache* cache);

void find_IP(Cache* cache);
void find_domain(Cache* cache);
void add_to_file();
void output_cache(Cache* cache);
void free_memory(Cache* cache);