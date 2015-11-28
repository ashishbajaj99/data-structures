// # The MIT License (MIT)
// # Copyright (c) 2015 Ashish Bajaj bajaj.ashish@gmail.com

// # Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
// # associated documentation files (the "Software"), to deal in the Software without restriction, including 
// # without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
// # copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the 
// # following conditions:
// # The above copyright notice and this permission notice shall be included in all copies or substantial 
// # portions of the Software.
// # THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT 
// # LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
// # IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// # WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
// # THE USE OR OTHER DEALINGS IN THE SOFTWARE.

// # A Makefile for the data-structures ANSI C project
// # This Makefile demonstrates and explains:
// # 1. Macros
// # 2. Targets and Dummy Targets
// # 3. Dependencies, and Pattern Rules

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/* Function Definitions */
void printList(Node *head) {
	int numNodesInALine = 8;
	int i = 0;
	while(head != NULL) {
		printf("| %d | 0x%08x | --> ", head->value, (int)head->next);
		head = head->next;
		i++;
		if(i%numNodesInALine == 0) {
			printf("\n");
		}
	}
	printf("NULL\n");

	return;
}

void addToStart(Node **headAndTail, int value) {
	Node *head = headAndTail[0];
	Node *tail = headAndTail[1];
	Node *toAdd = malloc(sizeof(Node));
	if(toAdd == NULL) {
		exit(EXIT_FAILURE);
	}

	toAdd->value = value;
	toAdd->next = head;
	head = toAdd;
	if(tail == NULL) {
		tail = head;
	}

	headAndTail[0] = head;
	headAndTail[1] = tail;
	return;
}

void addToEnd(Node **headAndTail, int value) {
	Node *head = headAndTail[0];
	Node *tail = headAndTail[1];
	Node *toAdd = malloc(sizeof(Node));
	if(toAdd == NULL) {
		exit(EXIT_FAILURE);
	}

	toAdd->value = value;
	toAdd->next = NULL;
	if(tail != NULL) {
		tail->next = toAdd;
		tail = toAdd;
	} else {
		tail = toAdd;
		head = toAdd;
	}

	headAndTail[0] = head;
	headAndTail[1] = tail;
	return;
}

void removeFromStart(Node **headAndTail) {
	Node *head = headAndTail[0];
	Node *tail = headAndTail[1];
	Node *toDelete;

	if(head != NULL) {
		toDelete = head;
		head = head->next;
		if(head == NULL) {
			tail = NULL;
		}
		free(toDelete);
	}

	headAndTail[0] = head;
	headAndTail[1] = tail;
	return;	
}

void removeFromEnd(Node **headAndTail) {
	Node *head = headAndTail[0];
	Node *tail = headAndTail[1];
	Node *toDelete = tail, *previous = NULL, *iterator = head;

	// Case #1
	// Empty list, do nothing
	if(head == NULL) {
		return;
	}

	// Case #2
	// Only one node, remove it and return
	if(iterator->next == NULL) {
		free(toDelete);
		head = NULL;
		tail = NULL;
	} else {
	// Case #3
	// More than one node, iterate and find previous to tail
		while(iterator->next != NULL) {
			previous = iterator;
			iterator = iterator->next;
		}
		tail = previous;
		tail->next = NULL;
		free(toDelete);
	}

	headAndTail[0] = head;
	headAndTail[1] = tail;
	return;	
}
