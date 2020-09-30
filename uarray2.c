/*
Sourivong Thepsimoung
Jacob Hampton
Professor Daniels 
CSC 411 
Due Date: October 2nd 2020
*/

#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "array.h"
#include "arrayrep.h"
#include "mem.h"
#include "uarray2.h"

#define T UArray2_T
//#define T Array_T

static struct T {
    int width;
    int height;
    int size;
    char *array;
    UArray_T outer;

};

T UArray2_new(int width, int height, int size){
    UArray_T outer = UArray_new(width, sizeof(UArray_T));

    assert(width && height && size > 0);

    for (int i = 0; i < width; i++){
        UArray_T inner = UArray_new(height, size);

        UArray_T *inner_temp = UArray_at(outer, i);
        *inner_temp = inner; 
    }
    T arr;

    NEW(arr);
    arr->height = height;
    arr->width = width;
    arr->size = size;
    arr -> outer = outer;
    
    return arr;

}

int UArray2_width(T array){
    assert(array);
    return array -> width;
}

int UArray2_height(T array){
    assert(array);
    return array -> height;
}

int UArray2_size(T array) {
    assert(array);
    return array->size;
}

int UArray2_free(T* array){
    assert(array && *array);
    FREE((*array)-> array);
    FREE(*array);
    
}

void *UArray2_at(T arry, int i, int y){
    assert(arry);
    assert(i >= 0 && y >=0 && i < arry -> width && y< arry->height);
    return ((arry-> array + i*arry-> size) + y* arry-> size);

}

// row by row
void UArray2_map_row_major(T arr, 
    void apply(int row, int col, T *arr, void *elem, void *cl), void* cl){
        assert(arr);
        for(int j = 0; j < arr-> height;j++){
            for(int i = 0; i < arr-> width;i++){
                apply(i, j, arr, UArray2_at(arr, i, j), cl);
            }
        }
}

// column by column 
void UArray2_map_col_major(T arr, 
        void apply(int row, int col, T *arr, void *elem, void *cl), void* cl){

            assert(arr);
            for(int i=0; i < arr-> width; i++){
                for (int j = 0; i < arr-> height; j++){
                    apply(i, j, arr, UArray2_at(arr, i, j), cl);
                }
            }          
}            
            
       
            