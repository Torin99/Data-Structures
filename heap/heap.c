/*
 -------------------------------------
 Author:  Torin Borton-McCallum
 File:    heap.c
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "heap.h"

HEAP* new_heap(int capacity) {
	HEAP *source;

	source = malloc(sizeof *source); 
	source->hnap = (HNODE*) malloc(capacity * (sizeof *source->hnap));
	source->capacity = capacity;
	source->size = 0;

	return (source);
}

void insert(HEAP *heap, HNODE new_node) {
	int index;
	HNODE *temp;
	if (heap->size == heap->capacity) {
		heap->capacity *= 2;
		temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
		if (temp) {
			heap->hnap = temp;
		} else {
			temp = malloc(sizeof(HNODE) * heap->capacity);
			if (temp) {
				memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
				free(heap->hnap);
				heap->hnap = temp;
			} else {
				printf("array resize failed\n");
			}
		}
	}
	index = heap->size;
	heap->hnap[index] = new_node;
	heap->size++;
	heapify(heap);

}

HNODE extract_min(HEAP *heap) {
	HNODE val = heap->hnap[0];
	heap->hnap[0] = heap->hnap[heap->size - 1];
	heap->hnap[heap->size - 1].data = 0;
	heap->hnap[heap->size - 1].key = 0;
	heap->size--;

	if ((float) ((float) heap->size / (float) heap->capacity) <= 0.25) {
		heap->capacity /= 4;
	}

	heapify(heap);
	return val;

}

void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value) {
	heap->hnap[node_index].key = key_value;

	heapify(heap);
}

int find_index(HEAP *heap, DATA value) {
	for (int i = 0; i < heap->size; i++) {
		if (heap->hnap[i].data == value) {
			return i;
		}
	}
	return -1;
}

void display_heap(HEAP *hp) {
	printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
	printf("(index, key, data):\n");
	int i;
	for (i = 0; i < hp->size; i++) {
		printf("(%d %d %d) ", i, hp->hnap[i].key, hp->hnap[i].data);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}

int cmp(KEYTYPE a, KEYTYPE b) {
	if (a < b)
		return -1;
	else if (a == b)
		return 0;
	else
		return 1;
}


void heapify(HEAP *source) {
	HNODE temp;
	int sorted = 0;

	while (sorted == 0) {
		sorted = 1;
		for (int i = 0; i < source->size; i++) {
			int parent = (i - 1) / 2;
			if (source->hnap[i].key < source->hnap[parent].key) {
				temp = source->hnap[i];
				source->hnap[i] = source->hnap[parent];
				source->hnap[parent] = temp;
				sorted = 0;
			}
		}
	}
}

