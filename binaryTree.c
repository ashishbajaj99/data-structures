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

#include <stdlib.h>
#include "binaryTree.h"

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