/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 File:    linked_list.h
 -------------------------------------
 */

typedef struct record {
	char name[40];
	float score;
} RECORD;


typedef struct node {
	RECORD data;
	struct NODE *next;
} NODE;

void display(NODE *start);

NODE* search(NODE *start, char *name);

void insert(NODE **startp, char *name, float score);

int delete(NODE **startp, char *name);

void clean(NODE **startp);


