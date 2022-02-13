/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 File:    hash.h
 -------------------------------------
 */

extern int htsize;

typedef struct hashnode {
	char name[10]; 
	int value;
	struct hashnode *next;
} HTNODE;

typedef struct hashtable {
	HTNODE **hnp;    // pointer pointing to the array of hashnode pointers
	int size;          // hash table size, maximum number of different indices
	int count;         // number of data elements in the hash table
} HASHTABLE;

int hash(char *name);

HTNODE* new_hashnode(char *name, int vale);

HASHTABLE* new_hashtable(int size);

HTNODE* search(HASHTABLE *ht, char *name);

int insert(HASHTABLE *ht, HTNODE *np);

int delete(HASHTABLE *ht, char *name);

void clean_hash(HASHTABLE **htp);

void display_hashtable(HASHTABLE *ht, int option);

