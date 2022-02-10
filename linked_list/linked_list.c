/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 File: linked_list.c
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

void display(NODE *start) {
	NODE *np = start;
	while (np != NULL) {
		printf("%s,%.1f\n", np->data.name, np->data.score);
		np = np->next;
	}
}
NODE* search(NODE *startp, char *name) {
	NODE *np = startp;
	int found = 0;
	while (np != NULL && found == 0) {
		if (strcmp(np->data.name, name) == 0)
			found = 1;
		np = np->next;
	}
	if (found == 0)
		return NULL;
	else
		return np;
}

void insert(NODE **startp, char *name, float score) {
	NODE *p = (NODE*) malloc(sizeof(NODE));
	strcpy(p->data.name, name);
	p->data.score = score;
	p->next = NULL;
	NODE *prev = NULL;
	NODE *ptr = *startp;
	while (ptr != NULL) {
		if (strcmp(ptr->data.name, name) >= 0)
			break;
		prev = ptr;
		ptr = ptr->next;
	}
	if (prev == NULL) {
		*startp = p;
		p->next = ptr;
	} else {
		prev->next = p;
		p->next = ptr;
	}
}

int delete(NODE **startp, char *name) {
	NODE *prev = NULL;
	NODE *ptr = *startp;
	while (ptr != NULL) {
		if (strcmp(ptr->data.name, name) == 0)
			break;
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr != NULL) {
		prev->next = ptr->next;
		free(ptr);
		return 0;
	} else
		return -1;

}
void clean(NODE **startp) {
	NODE *p = *startp;
	NODE *prev = NULL;
	while (p != NULL) {
		prev = p;
		p = p->next;
		free(prev);
	}
	*startp = NULL;

}

