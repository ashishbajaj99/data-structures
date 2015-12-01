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
#include "queue.h"

/* Function Definitions */
void enqueue(qNode **headAndTail, Tree *value) {
    qNode *head = headAndTail[0];
    qNode *tail = headAndTail[1];
    qNode *toAdd = malloc(sizeof(qNode));
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

Tree *dequeue(qNode **headAndTail) {
    qNode *head = headAndTail[0];
    qNode *tail = headAndTail[1];
    qNode *toDelete = tail, *previous = NULL, *iterator = head;
    Tree *toRet = toDelete->value;

    // Case #1
    // Empty list, do nothing
    if(head == NULL) {
        return NULL;
    }

    // Case #2
    // Only one qNode, remove it and return
    if(iterator->next == NULL) {
        free(toDelete);
        head = NULL;
        tail = NULL;
    } else {
    // Case #3
    // More than one qNode, iterate and find previous to tail
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
    return toRet; 
}

int findInQueue(qNode **headAndTail, Tree *value) {
    qNode *head = headAndTail[0];
    qNode *tail = headAndTail[1];
    int toRet = 0;

    while(head != NULL) {
        if(head->value == value) {
            toRet = 1;
            break;
        }
        head = head->next;
    }

    return toRet;
}
