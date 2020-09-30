/*
// Sourivong Thepsimoung
// Professor Daniels 
// CSC 411 Assignment 02
// Due Date: September 25th 2020 
*/

#ifndef BIT2_INCLUDED
#define BIT2_INCLUDED
#define T Bit2_T

typedef struct T *T;


// creator, initialize new Bit2 w/ width and height
extern T Bit2_new(int width, int height, int size);

// destroyer, deallocates the memory 
extern void Bit2_free(T *set);

// observer, return the width of a Bit2
extern int Bit2_width(T set);

// observer, return the height of a Bit2
extern int Bit2_height(T set);

// observer, returns the numbers of ones in a set
extern int Bit_count (T set);

// observer, gets the value of the (i,j) position in the array
extern int Bit2_get(T set, int i, int j);

// mutator, changes the (i,j) position with the bit value
extern int Bit2_put(T set, int i, int j, int bit);

// observer, iterate through a 2D array and perform apply function on each elem
// iterate row by row
void Bit2_map_row_major(T* arr, 
        void apply(int r,int c, int bit, T* arr2, void *cl), void* cl);

// observer, iterate through a 2D array and perform apply function on each elem
// iterate column by column
void Bit2_map_col_major(T* arr, 
        void apply(int r,int c, int bit, T* arr2, void *cl), void* cl);

#undef T
#endif
