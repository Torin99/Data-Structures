/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 File:    stack.c
 -------------------------------------
 */
#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
	np->next = sp->top;
	sp->top = np;
}

NODE* pop(STACK *sp) {
	if (sp->top == NULL)
		return NULL;
	NODE *pop = sp->top;
	sp->top = sp->top->next;
	pop->next = NULL;
	return pop;
}

void clean_stack(STACK *sp) {
	NODE *ptr = sp->top;
	clean(&ptr);
}
