/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 File: queue.h
 -------------------------------------
 */

#include "node.h"

typedef struct queue {
	NODE *front;
	NODE *rear;
} QUEUE;

void enqueue(QUEUE *qp, NODE *np);
NODE* dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);


