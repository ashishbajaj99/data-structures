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
#include "sorting.h"

/* Function Prototypes */
int testLinkedList(void);
int testBinarySearchTree(void);
int testSorting(void);
int errorMsg(void);

/* Main Test Function */
int main(int argc, char *argv[]) {

	int (*functionLUT[])(void) = {
		testLinkedList,
		testBinarySearchTree,
		testSorting
	};

	if(argc != 2) {
		return errorMsg();
	}

	if(strcmp("linked-list", argv[1]) == 0) {
		return functionLUT[0]();
	}

	if(strcmp("bst", argv[1]) == 0) {
		return functionLUT[1]();
	}

	if(strcmp("sort", argv[1]) == 0) {
		return functionLUT[2]();
	}

	return errorMsg();
}

int errorMsg(void) {
	printf("Usage: ./test-example <data-structure-name>\n");
	printf("Valid Inputs for <data-structure-name>: linked-list, binary-search-tree, sort\n");
	printf("\nExample: ./test-example linked-list\n");
	return EXIT_FAILURE;
}

int testSorting(void) {
	int i;
	int a[9] = {12, 1, 4, 0, 55, 1, 3, 19, 20};
	int b[2] = {100, 10};

	printf("\nstarting sort of 9 element array: ");
	for(i=0; i<9; i++) {
		printf("%d, ", a[i]);
	}
	printf("\n");

	mergeSort(a, 9);

	printf("output of merge sort: ");
	for(i=0; i<9; i++) {
		printf("%d, ", a[i]);
	}
	printf("\n");	

	printf("\nstarting sort of 1 element array: ");
	for(i=0; i<2; i++) {
		printf("%d, ", b[i]);
	}
	printf("\n");

	mergeSort(b, 2);

	printf("output of merge sort: ");
	for(i=0; i<2; i++) {
		printf("%d, ", b[i]);
	}
	printf("\n");	

	return EXIT_SUCCESS;
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
	Tree *singleNodeTree = malloc(sizeof(Tree));
	Tree *test[2];	
	if(singleNodeTree == NULL) {
		exit(EXIT_FAILURE);
	}
	singleNodeTree->value = 100;
	singleNodeTree->left = NULL;
	singleNodeTree->right = NULL;

	printf("Start Test of Binary Search Tree.\n");
	printf("Initial contents of the tree:\n");
	print_ascii_tree(head);

	printf("\nadd() 5 to the tree\n");
	head = addToTree(head, 5);
	print_ascii_tree(head);
	printf("\nadd() 2 to the tree\n");
	head = addToTree(head, 2);
	print_ascii_tree(head);
	printf("\nadd() 12 to the tree\n");	
	head = addToTree(head, 12);
	print_ascii_tree(head);
	printf("\nadd() 1 to the tree\n");	
	head = addToTree(head, 1);
	print_ascii_tree(head);
	printf("\nadd() 8 to the tree\n");	
	head = addToTree(head, 8);
	print_ascii_tree(head);
	printf("\nadd() 4 to the tree\n");	
	head = addToTree(head, 4);
	print_ascii_tree(head);
	printf("\nadd() 3 to the tree\n");	
	head = addToTree(head, 3);
	print_ascii_tree(head);
	printf("\nadd() 10 to the tree\n");	
	head = addToTree(head, 10);
	print_ascii_tree(head);
	printf("\nadd() 9 to the tree\n");	
	head = addToTree(head, 9);
	print_ascii_tree(head);	
	printf("\nadd() 11 to the tree\n");	
	head = addToTree(head, 11);
	print_ascii_tree(head);	
	printf("\nadd() 7 to the tree\n");	
	head = addToTree(head, 7);
	print_ascii_tree(head);		

	if( (test[0] = findInTree(head, 3)) == NULL) {
		printf("\nfind(3) = Value Not Found\n");
	} else {
		printf("\nfind(3) = %d\n", test[0]->value);
	}

	if( (test[0] = findInTree(head, 7)) == NULL) {
		printf("\nfind(7) = Value Not Found\n");
	} else {
		printf("\nfind(7) = %d\n", test[0]->value);
	}

	if( (test[0] = findInTree(head, 4)) == NULL) {
		printf("\nfind(4) = Value Not Found\n");
	} else {
		printf("\nfind(4) = %d\n", test[0]->value);
	}

	findParentInTree(head, head, 3, test);
	if( test[1] == NULL) {
		printf("\nfindParentOfNode(3) = Value Not Found\n");
	} else {
		printf("\nfindParentOfNode(%d) = %d\n", test[0]->value, test[1]->value);
	}

	findParentInTree(head, head, 5, test);
	if( test[1] == NULL) {
		printf("\nfindParentOfNode(5) = Value Not Found\n");
	} else {
		printf("\nfindParentOfNode(%d) = %d\n", test[0]->value, test[1]->value);
	}

	findParentInTree(head, head, 2, test);
	if( test[1] == NULL) {
		printf("\nfindParentOfNode(2) = Value Not Found\n");
	} else {
		printf("\nfindParentOfNode(%d) = %d\n", test[0]->value, test[1]->value);
	}

	findParentInTree(head, head, 9, test);
	if( test[1] == NULL) {
		printf("\nfindParentOfNode(9) = Value Not Found\n");
	} else {
		printf("\nfindParentOfNode(%d) = %d\n", test[0]->value, test[1]->value);
	}

	printf("Depth of the tree = %d\n", getTreeDepth(head, 0));
	inOrderTraversal(head);
	preOrderTraversal(head);
	postOrderTraversal(head);	
	breadthFirstSearch(head);		
	/* Delete Order: 1, 3, 12, 8, 5 */
	printf("\nbefore removing any items\n");
	print_ascii_tree(head);		
	printf("\nremove() 1 from the tree\n");	
	head = removeFromTree(head, 1);
	print_ascii_tree(head);		
	printf("\nremove() 3 from the tree\n");	
	head = removeFromTree(head, 3);
	print_ascii_tree(head);		
	printf("\nremove() 12 from the tree\n");	
	head = removeFromTree(head, 12);
	print_ascii_tree(head);		
	printf("\nremove() 8 from the tree\n");	
	head = removeFromTree(head, 8);
	print_ascii_tree(head);		
	printf("\nremove() 5 from the tree\n");	
	head = removeFromTree(head, 5);
	print_ascii_tree(head);			
	printf("\nremove() 11 from the tree\n");	
	head = removeFromTree(head, 11);
	print_ascii_tree(head);				
	printf("Depth of the tree = %d\n", getTreeDepth(head, 0));
	inOrderTraversal(head);
	breadthFirstSearch(head);		

	printf("\nsinglNodeTests start here: \n");
	print_ascii_tree(singleNodeTree);
	inOrderTraversal(singleNodeTree);

	printf("\n remove() 1 from tree\n");
	if(removeFromTree(singleNodeTree, 1) == NULL) {
		printf("Node Not Found, nothing removed\n");
	}
	printf("Depth of the singleNodeTree = %d\n", getTreeDepth(singleNodeTree, 0));	

	printf("\n remove() 100 from tree\n");
	singleNodeTree = removeFromTree(singleNodeTree, 100);
	printf("Depth of the singleNodeTree = %d\n", getTreeDepth(singleNodeTree, 0));

	return EXIT_SUCCESS;
}