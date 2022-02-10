/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 file description: queue
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
	if (qp->front == NULL || qp->rear == NULL) {
		qp->front = np;
		qp->rear = np;
	} else {
		qp->rear->next = np;
		qp->rear = np;
	}
}

NODE* dequeue(QUEUE *qp) {
	NODE *ptr = qp->front;
	qp->front = qp->front->next;
	ptr->next = NULL;
	return ptr;
}

void clean_queue(QUEUE *qp) {
	NODE *ptr = qp->front;
	clean(&ptr);
}

