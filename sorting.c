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
#include "sorting.h"

void mergeSort(int *a, int length) {
    int leftArraySize = length >> 1;
    int rightArraySize = length - leftArraySize;

    int i = 0;
    int *left, *right;

    if(length < 2) {
        return;
    }

    left = malloc(sizeof(int)*leftArraySize);
    if(left == NULL) {
        printf("Out of memory leftArraySize = %d\n", leftArraySize);
        exit(EXIT_FAILURE);
    }
    right = malloc(sizeof(int)*rightArraySize);
    if(right == NULL) {
        printf("Out of memory rightArraySize = %d\n", rightArraySize);
        exit(EXIT_FAILURE);
    }

    printf("Constructing Left list = ");
    for(i=0; i<leftArraySize; i++) {
        left[i] = a[i];
        printf("%d, ", left[i]);        
    }

    printf("; Right list = ");
    for(i=leftArraySize; i<length; i++) {
        right[i-leftArraySize] = a[i];
        printf("%d, ", right[i-leftArraySize]);
    }
    printf("\n");

    mergeSort(left, leftArraySize);
    mergeSort(right, rightArraySize);
    merge(left, right, a, leftArraySize, rightArraySize);
    free(left);
    free(right);
    return;
}

void merge(int *leftList, int *rightList, int *output, int leftListLength, int rightListLength) {
    int i, length = leftListLength+rightListLength;
    printf("Merge called with following inputs: leftList = ");
    for(i=0; i<leftListLength; i++) {
        printf("%d, ", leftList[i]);
    }
    printf("; rightList = ");
    for(i=0; i<rightListLength; i++) {
        printf("%d, ", rightList[i]);
    }
    printf("\n");
    for(i=0; i<length; i++) {

        // Case #1: If leftListLength has reached length/2
        //          Then simply copy all the contents of rightList
        if(leftListLength == 0) {
            *output++ = *rightList++;
            rightListLength--;
        } else if(rightListLength == 0) {
        
        // Case #2: If rightListLength has reached length/2
        //          Then simply copy all the contents of rightList
            *output++ = *leftList++;
            leftListLength--;
        } else {
        
        // Case #3: Neither of the lists have reached their max
        //          Then pick the smaller of the two values 
            if(*leftList < *rightList) {
                *output++ = *leftList++;
                leftListLength--;
            } else {
                *output++ = *rightList++;
                rightListLength--;
            }            
        }
    }
}