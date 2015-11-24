#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

/* Function Prototypes */
void printList(Node *);
void addToStart(Node **, int);
void addToEnd(Node **, int);
void removeFromStart(Node **);
void removeFromEnd(Node **);

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

	if(head == NULL) {
		return;
	}

	while(iterator->next != NULL) {
		previous = iterator;
		iterator = iterator->next;
	}

	if(previous != NULL) {
		tail = previous;
		tail->next = NULL;
		free(toDelete);
	} else {
		head = NULL;
		tail = NULL;
	}


	headAndTail[0] = head;
	headAndTail[1] = tail;
	return;	
}

/* Main Test Function */
int main(void) {

	Node *headAndTail[2];

	headAndTail[0] = NULL; //head
	headAndTail[1] = NULL; //tail

	addToEnd(headAndTail, 2);
	addToEnd(headAndTail, 3);
	addToEnd(headAndTail, 7);

	printList(headAndTail[0]);

	removeFromEnd(headAndTail);
	printList(headAndTail[0]);

	removeFromEnd(headAndTail);
	printList(headAndTail[0]);

	removeFromStart(headAndTail);
	printList(headAndTail[0]);

	return EXIT_SUCCESS;
}
