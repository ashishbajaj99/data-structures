#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

void printList(Node *);

int main(void) {

	Node *head, *tail;
	Node first, second, third;

	first.value = 2;
	first.next = &second;
	second.value = 3;
	second.next = &third;
	third.value = 7;
	third.next = NULL;

	head = &first;
	tail = &third;

	printList(head);

	// return EXIT_SUCCESS;
}

void printList(Node *head) {
	int numNodesInALine = 8;
	int i = 0;
	while(head != NULL) {
		printf("| %d | %d | --> ", head->value, (int)head->next);
		head = head->next;
		i++;
		if(i%numNodesInALine == 0) {
			printf("\n");
		}
	}
	printf("NULL\n");

	return;
}

Node * addToStart(Node *head, Node *tail) {

}