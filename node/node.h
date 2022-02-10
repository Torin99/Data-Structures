/*--------------------------------------------------
Author:  Torin Borton-McCallum
File:    node.h
--------------------------------------------------
*/

typedef struct node {
	struct node* next;
	int data; 
	int type; 
} NODE;

NODE *new_node(int data, int type);
void display(NODE *top);
void clean(NODE **top);

