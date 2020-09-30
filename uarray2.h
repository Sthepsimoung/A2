/*
// Sourivong Thepsimoung
// Professor Daniels 
// CSC 411 Assignment 02
// Due Date: September 25th 2020 
*/

#ifndef UARRAY2_INCLUDED
#define UARRAY2_INCLUDED

#include <stdlib.h>
#include "array.h"
#define T UArray2_T
typedef struct T *UArray2_T;

// creator, initializes new UArray2_T w/ width and height 
// stores bytes size
T UArray2_new(int width, int height, int size);

// destroyer, deallocates the memory in the array
extern int UArray2_free(UArray2_T* arr);

// observer, returns the size of an elem in nested array
extern int UArray2_size(UArray2_T arr);

// observer, returns the width of the 2D array
extern int UArray2_width(UArray2_T arr);

// observer, returns the height of the 2D array
extern int UArray2_height(UArray2_T arr);

// observer, returns the pointer of the elem that is stored
extern void *UArray2_at(UArray2_T, int i, int y);

// observer, iterate through a 2D array and perform apply function on each elem
// iterate row by row
void UArray2_map_row_major(UArray2_T arr, 
        void apply(int i, int j, UArray2_T* arr2,void *elem, void *cl), void* cl);

// observer, iterate through a 2D array and perform apply function on each elem
// iterate column by column
void UArray2_map_col_major(UArray2_T arr,
        void apply(int i, int j, UArray2_T* arr2, void *elem, void *cl), void* cl);


#undef T
#endif
