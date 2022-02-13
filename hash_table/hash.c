/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 File:    hash.c
 -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

int hash(char *word) {
	unsigned int hash = 0, i;
	for (i = 0; word[i] != '\0'; i++) {
		hash = 31 * hash + word[i];
	}
	return hash % htsize;
}
HTNODE* new_hashnode(char *name, int value) {
	HTNODE *myhash = (HTNODE*) malloc(sizeof(HTNODE)); //create space
	myhash->value = value;		//set node value to input value
	strcpy(myhash->name, name);	//copy input name to node name
	myhash->next = NULL;
	return myhash;
}

HASHTABLE* new_hashtable(int size) {
	HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));	//create space for table
	ht->hnp = (HTNODE**) malloc(sizeof(HTNODE**) * size);//create space for each empty hash node
	for (int i = 0; i < size; i++)
		*(ht->hnp + i) = NULL; 	//set each hash node to an empty value
	ht->size = size; 			//set size of hash table to input value
	ht->count = 0; 				//new empty table therefore count is 0
	return ht;

}

HTNODE* search(HASHTABLE *ht, char *name) {
	int i = hash(name);
	HTNODE *ptr = ht->hnp[i];
	if (ptr->name != NULL && strcmp(ptr->name, name) == 0)
		return ptr;
	else
		return NULL;
}

int insert(HASHTABLE *ht, HTNODE *np) {
	int i = hash(np->name);
	if (search(ht, np->name) == NULL) {
		ht->hnp[i] = np;
		ht->count++;
		return 1;
	} else {
		ht->hnp[i]->value = np->value;
		return 0;
	}

}

int delete(HASHTABLE *ht, char *name) {
	int i = hash(name);
	if (search(ht, name) == NULL) {
		return 0;
	} else {
		ht->hnp[i] = NULL;
		ht->count--;
		return 1;
	}
}

void clean_hash(HASHTABLE **htp) {
	if (*htp == NULL)
		return;
	HASHTABLE *ht = *htp;
	HTNODE *p, *temp;
	int i;
	for (i = 0; i < ht->size; i++) {
		p = ht->hnp[i];
		while (p) {
			temp = p;
			p = p->next;
			free(temp);
		}
		ht->hnp[i] = NULL;
	}
	free(ht->hnp);
	ht->hnp = NULL;
	*htp = NULL;
}

void display_hashtable(HASHTABLE *ht, int option) {
	int i = 0;
	HTNODE *p;
	if (option == 0) {
		printf("size:  %d\n", ht->size);
		printf("count: %d\n", ht->count);
		printf("hash data:\nindex: list of the data elements");
		for (i = 0; i < ht->size; i++) {
			p = *(ht->hnp + i);
			if (p)
				printf("\n%2d: ", i);

			while (p) {
				printf("(%s, %d) ", p->name, p->value);
				p = p->next;
			}
		}
		printf("\n");
	} else {

		for (i = 0; i < ht->size; i++) {
			p = *(ht->hnp + i);
			while (p) {
				printf("%s=%d\n", p->name, p->value);
				p = p->next;
			}
		}

	}

}

