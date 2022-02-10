/*
 ------------------------------------- 
 Author:  Torin Borton-McCallum
 File:    stack.h
 -------------------------------------
 */

#include "node.h"

typedef struct stack {
	NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE* pop(STACK *sp);
void clean_stack(STACK *sp);

