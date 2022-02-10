/*--------------------------------------------------
 Author:  Torin Borton-McCallum 
 File:    node.c
 --------------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include "node.h"

NODE* new_node(int data, int type) {
	NODE *np = (NODE*) malloc(sizeof(NODE));
	np->next = NULL;
	np->data = data;
	np->type = type;
	return np;
}

void display(NODE *top) {
	while (top) {
		if (start->type != 0)
			printf("%c ", top->data);
		else printf("%d ", top->data);
		top = top->next;
	}
}

void clean(NODE **top) {
	NODE *curr = *top;
	while (curr) {
		NODE *tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*top = NULL;
}
