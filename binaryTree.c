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
#include "binaryTree.h"
#include "queue.h"

/* Function Prototypes */
void addTreeHelper(Tree *, Tree *);

/* Function Definitions */
Tree *addToTree(Tree *head, int value) {
	Tree *toAdd = malloc(sizeof(Tree));
	if(toAdd == NULL) {
		exit(EXIT_FAILURE);
	}
	toAdd->value = value;
	toAdd->left = NULL;
	toAdd->right = NULL;

	if(head == NULL) {
		return toAdd;
	} else {
		addTreeHelper(head, toAdd);
	}

	return head;
}

void addTreeHelper(Tree *head, Tree *toAdd) {
	if(toAdd->value < head->value) {
		if(head->left != NULL) {
			addTreeHelper(head->left, toAdd);			
		} else {
			head->left = toAdd;
		}
	} else {
		if(head->right != NULL) {
			addTreeHelper(head->right, toAdd);
		} else {
			head->right = toAdd;
		}
	}
}

Tree *findInTree(Tree *head, int value) {
	if(head == NULL) {
		return head;
	}

	if(head->value == value) {
		return head;
	}

	if(value < head->value) {
		return findInTree(head->left, value);
	} else {
		return findInTree(head->right, value);
	}
}

/** @brief Finds the node that contains the param value
 *         and updates the nodeAddress and nodeParentAddress
 *         in the param output
 *  @param head: The address of the first node of the tree
 *  @param parent: Used for recursion, caller should pass in head here
 *  @param value: The value to find in the Tree
 *  @param output: Array of Tree pointers. 
 *                   output[0]->nodeWithValue,
 *                   output[1]->parentOfNodeWithValue
  *  @return Void, the output param is updated
 */
void findParentInTree(Tree *head, Tree *parent, int value, Tree **output) {

	if(head == NULL) {
		output[0] = NULL;
		output[1] = NULL;
		return;
	}

	if(head->value == value) {
		output[0] = head;
		output[1] = parent;
		return;
	}

	if(value < head->value) {
		findParentInTree(head->left, head, value, output);
	} else {
		findParentInTree(head->right, head, value, output);
	}
}

/** @brief Finds the leftMost node relative to the head of subtree
 *         that is passed into the function.
 *  @param head: The address of the first node of the tree
 *  @param parent: Used for recursion, caller should pass in head here
 *  @param output: Array of Tree pointers. 
 *                   output[0]->leftMostNode,
 *                   output[1]->parentOfLeftMostNode
  *  @return Void, the output param is updated
 */
void getLeftMostNode(Tree *head, Tree *parent, Tree **output) {
	if(head == NULL) {
		output[0] = NULL;
		output[1] = NULL;
		return;
	}

	if(head->left == NULL) {
		output[0] = head;
		output[1] = parent;
		return;
	} else {
		getLeftMostNode(head->left, head, output);
	}
}

Tree *removeFromTree(Tree *head, int value) {
	Tree *toDeleteArray[2];
	Tree *toDelete, *toDeleteParent;
	Tree *toReplaceArray[2];
	Tree *toReplace, *toReplaceParent;

	// Find toDelete and toDeleteParent
	findParentInTree(head, head, value, toDeleteArray);
	toDelete = toDeleteArray[0];
	toDeleteParent = toDeleteArray[1];

	// Various Cases:
	// Case #1: if empty tree, return empty tree
	if(head == NULL) {
		return NULL;
	}

	// Case #2: if no node found, return NULL, nothing to delete
	if(toDelete == NULL) {
		return NULL;
	}

	// We are ready to go through the various deletion cases that are needed
	// so that after the deletion, the resultant tree continues to conform
	// to the rules of the BST

	// Case #3: toDelete has no right child
	//          In this case, we need to perform the following steps:
	//          1. Pick toReplace = toDelete->left 
	if(toDelete->right == NULL) {
		toReplace = toDelete->left;
	} else {

	// Case #4a: toDelete has right child, but toDelete->right, doesn't have a leftMostChild
	//           In this case, we need to perform the following steps:
	//           1. Pick toReplace = toDelete->right (toReplace has no left child here)
	//           2. Attach toReplace->left = toDelete->left
		getLeftMostNode(toDelete->right, toDelete->right, toReplaceArray);
		toReplace = toReplaceArray[0];
		toReplaceParent = toReplaceArray[1];

		if(toReplace == toDelete->right) {
			toReplace->left = toDelete->left;
		} else {

	// Case #4b: toDelete has right child, and has a leftMostChild
	//           In this case, we need to perform the following steps:
	//           1. Pick toReplace = leftMostNode(toDelete->right)
	//           2. toReplaceParent->left = toReplace->right	
	//           3. toReplace->left = toDelete->left
	//           4. toReplace->right = toDelete->right
			toReplaceParent->left = toReplace->right;
			toReplace->left = toDelete->left;
			toReplace->right = toDelete->right;
		}		
	}

	// Final Step: Attach toDeleteParent to toReplace based on direction
	if(toDelete == head) {
		head = toReplace;
	} else {
		if(value < toDeleteParent->value) {
			toDeleteParent->left = toReplace;
		} else {
			toDeleteParent->right = toReplace;
		}		
	}

	free(toDelete);
	return head;

}

int getTreeDepth(Tree *head, int depth) {
	int leftDepth, rightDepth;

	if(head == NULL) {
		return depth;
	}

	leftDepth = getTreeDepth(head->left, depth++);
	rightDepth = getTreeDepth(head->right, depth++);
	return max(leftDepth, rightDepth);
}


void inOrderTraversal(Tree *head){
	if(head == NULL) {
		return;
	}

	inOrderTraversal(head->left);
	printf("Inorder Processing Node = %d\n", head->value);
	inOrderTraversal(head->right);
}

void preOrderTraversal(Tree *head){
	if(head == NULL) {
		return;
	}

	printf("Pre-Order Processing Node = %d\n", head->value);
	preOrderTraversal(head->left);
	preOrderTraversal(head->right);
}

void postOrderTraversal(Tree *head){
	if(head == NULL) {
		return;
	}

	postOrderTraversal(head->left);
	postOrderTraversal(head->right);
	printf("Post-Order Processing Node = %d\n", head->value);	
}

void breadthFirstSearch(Tree *head) {
	qNode *neighborList[2], *visitedList[2];
	Tree *temp, *debug;
	neighborList[0] = NULL;
	neighborList[1] = NULL;
	visitedList[0] = NULL;
	visitedList[1] = NULL;

	// Case #1: If empty tree, we are done
	if(head == NULL) {
		return;
	}

	// Case #2: if tree with single node, process(head) and we are done
	if( (head->left == NULL) && (head->right == NULL) ) {
		printf("Breadth First Processing = %d\n", head->value);
		return;
	}

	// Case #3: start the breadthFirstSearch algorithm
	printf("Breadth First Processing = %d\n", head->value);
	enqueue(visitedList, head);
	if(head->left != NULL) {
		enqueue(neighborList, head->left);
	}
	if(head->right != NULL) {
		enqueue(neighborList, head->right);
	}

	while(neighborList[0] != NULL) {
		temp = dequeue(neighborList);
		printf("Breadth First Processing = %d\n", temp->value);
		enqueue(visitedList, temp);
		if(findInQueue(visitedList, temp->left) == 0) {
			if(temp->left != NULL) {
				enqueue(neighborList, temp->left);
			}
		}
		if(findInQueue(visitedList, temp->right) == 0) {
			if(temp->right != NULL) {
				enqueue(neighborList, temp->right);
			}
		}
	}
	return;
}