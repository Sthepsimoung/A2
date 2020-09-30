/*
Sourivong Thepsimoung
Jacob Hampton
Professor Daniels 
CSC 411 
Due Date: October 2nd 2020
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "assert.h"
#include "array.h"
#include "arrayrep.h"
#include "mem.h"
#include "uarray2.h"
#include "bit.h"
#include "bit2.h"

#define T Bit2_T
//#define BPW (8*sizeof (unsigned long))
//#define nwords(len) ((((len) + BPW - 1)&(~(BPW-1)))/BPW)
//#define nbytes(len) ((((len) + 8 - 1)&(~(8-1)))/8)

static struct T {
    int width;
    int height;
    Bit_T bit;
};

T Bit2_new(int width, int height, int size){
    T bit2;
    NEW(bit2);
    
    Bit_T bit = Bit_new(width*height);

    bit2 ->width = width;
    bit2 ->height = height;
    bit2 ->bit = bit;
    
    /*T arr; 
    int y = width*height;
    assert(y >= 0);
    NEW(arr);
    assert(arr);
    if (y > 0){
        arr -> words = CALLOC(nwords(y),
            sizeof(unsigned long));
    }
    else {
        arr -> words = NULL;
    }
    arr -> bytes = (unsigned char *) arr -> words;
    arr -> width = width;
    arr -> height = height;
    
    return arr;
    */
}

void Bit2_free(T *set){
   FREE(*set);
}


int Bit2_width(T set){
    assert(set);
    return set-> width;
}

int Bit2_height(T set){
    assert(set);
    return set-> height;
}

//int idxi = (idxr + idxc)+(idxr x (height-1))  


// observer, gets the value of the (i,j) position in the array
int Bit2_get(T set, int i, int j){
    assert(set);
    int elm = (i+j) + (i * (set->height - 1 ));
    return Bit_get(set,elm);

}

// mutator, changes the (i,j) position with the bit value
int Bit2_put(T set, int i, int j, int bit){
    int prev;
    assert(set);
    assert(bit == 0 || bit == 1);
    assert(i >= 0 && j >=0 && i < set -> width && j < set->height);


}
    



void Bit2_map_row_major(T* arr, 
        void apply(int n, int bit, T* arr2, void *cl), void* cl){

}

void Bit2_map_col_major(T* arr, 
        void apply(int n, int bit, T* arr2, void *cl), void* cl){
            
}
