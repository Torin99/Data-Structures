/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 File:    heap.h
 -------------------------------------
 */


#define MIN_CAPACITY 4

typedef int KEYTYPE;  
typedef int DATA;     

typedef struct heap_node { 
	KEYTYPE key;
	DATA data;
} HNODE;

typedef struct heap {
	unsigned int capacity; 
	unsigned int size;     
	HNODE *hnap;  
} HEAP;


void heapify(HEAP *source);


HEAP* new_heap(int capacity);

int find_index(HEAP *heap, DATA d);

void insert(HEAP *heap, HNODE a);

HNODE extract_min(HEAP *heap);

void decrease_key(HEAP *heap, int index, KEYTYPE new_key_value);

void display_heap(HEAP *heap);

int cmp(KEYTYPE a, KEYTYPE b);

