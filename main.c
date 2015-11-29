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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "asciiList.h"
#include "binaryTree.h"
#include "asciiTree.h"

/* Function Prototypes */
int testLinkedList(void);
int testBinarySearchTree(void);
int errorMsg(void);

/* Main Test Function */
int main(int argc, char *argv[]) {

	int (*functionLUT[])(void) = {
		testLinkedList,
		testBinarySearchTree
	};

	if(argc != 2) {
		return errorMsg();
	}

	if(strcmp("linked-list", argv[1]) == 0) {
		return functionLUT[0]();
	}

	if(strcmp("binary-search-tree", argv[1]) == 0) {
		return functionLUT[1]();
	}

	return errorMsg();
}

int errorMsg(void) {
	printf("Usage: ./test-example <data-structure-name>\n");
	printf("Valid Inputs for <data-structure-name>: linked-list, binary-search-tree\n");
	printf("\nExample: ./test-example linked-list\n");
	return EXIT_FAILURE;
}

int testLinkedList(void) {
	Node *headAndTail[2];	
	headAndTail[0] = NULL; //head
	headAndTail[1] = NULL; //tail

	printf("Start Test of Linked List.\n");
	printf("Initial contents of the list:\n");
	printList(headAndTail[0]);

	printf("\naddToEnd() 2, 3 and 7 to an empty list\n");
	addToEnd(headAndTail, 2);
	printList(headAndTail[0]);
	addToEnd(headAndTail, 3);
	printList(headAndTail[0]);
	addToEnd(headAndTail, 7);
	printList(headAndTail[0]);

	printf("\nremoveFromEnd() three times to make the list empty again\n");
	removeFromEnd(headAndTail);
	printList(headAndTail[0]);
	removeFromEnd(headAndTail);
	printList(headAndTail[0]);
	removeFromEnd(headAndTail);
	printList(headAndTail[0]);

	printf("\naddToStart() 2, 3 and 7 to an empty list\n");
	addToStart(headAndTail, 2);
	printList(headAndTail[0]);
	addToStart(headAndTail, 3);
	printList(headAndTail[0]);
	addToStart(headAndTail, 7);
	printList(headAndTail[0]);

	printf("\nremoveFromStart() three times to make the list empty again\n");
	removeFromStart(headAndTail);
	printList(headAndTail[0]);
	removeFromStart(headAndTail);
	printList(headAndTail[0]);
	removeFromStart(headAndTail);
	printList(headAndTail[0]);

	printf("\n Test error handling: removeFromEnd() and removeFromStart() on empty list\n");
	removeFromEnd(headAndTail);
	removeFromStart(headAndTail);
	printf("\n Testing Completed - No Errors\n");

	return EXIT_SUCCESS;
}

int testBinarySearchTree(void) {
	Tree *head = NULL;
	Tree *test = NULL;	
	printf("Start Test of Binary Search Tree.\n");
	printf("Initial contents of the tree:\n");
	print_ascii_tree(head);

	printf("\nadd() 3 to the tree\n");
	head = addToTree(head, 3);
	print_ascii_tree(head);
	printf("\nadd() 2 to the tree\n");
	head = addToTree(head, 2);
	print_ascii_tree(head);
	printf("\nadd() 7 to the tree\n");	
	head = addToTree(head, 7);
	print_ascii_tree(head);
	printf("\nadd() 1 to the tree\n");	
	head = addToTree(head, 1);
	print_ascii_tree(head);

	if( (test = findInTree(head, 3)) == NULL) {
		printf("\nfind(3) = Value Not Found\n");
	} else {
		printf("\nfind(3) = %d\n", test->value);
	}

	if( (test = findInTree(head, 7)) == NULL) {
		printf("\nfind(7) = Value Not Found\n");
	} else {
		printf("\nfind(7) = %d\n", test->value);
	}

	if( (test = findInTree(head, 4)) == NULL) {
		printf("\nfind(4) = Value Not Found\n");
	} else {
		printf("\nfind(4) = %d\n", test->value);
	}

	return EXIT_SUCCESS;
}