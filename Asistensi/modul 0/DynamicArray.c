#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dynamicarr_t {
  int *_arr;
  unsigned _size, _capacity;
} DynamicArray;

void dArray_init(DynamicArray *darray) {
  darray->_size = 0;
  darray->_arr = NULL;
  darray->_capacity = 1;
}

bool dArray_isEmpty(DynamicArray *darray) {
  return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, int value)
{
    if (darray->_size + 1 >= darray->_capacity) {
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        if (newArr == NULL) {
            printf("Memory allocation error\n");
            exit(1);
        }

        for (unsigned it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        free(oldArray);
        darray->_arr = newArr;
    }
    darray->_arr[darray->_size++] = value;
}


void dArray_popBack(DynamicArray *darray) {
  if(!dArray_isEmpty(darray)) darray->_size--;
}

int dArray_back(DynamicArray *darray) {
  if(!dArray_isEmpty(darray)) {
    return darray->_arr[darray->_size - 1];
  }
}

int dArray_front(DynamicArray *darray) {
  if(!dArray_isEmpty(darray))
    return darray->_arr[0];
  return 0;
}

void dArray_setAt(DynamicArray *darray, unsigned index, int value) {
  if(!dArray_isEmpty(darray)) {
    if(index >= darray->_size) 
      darray->_arr[darray->_size-1] = value;
    else
      darray->_arr[index] = value;
  }
}

int dArray_getAt(DynamicArray *darray, unsigned index) {
  if(!dArray_isEmpty(darray)) {
    if(index >= darray->_size)
      return darray->_arr[darray->_size-1];
    else
      return darray->_arr[index];
  }
}

void dArray_insertAt(DynamicArray *darray, unsigned index, int value) {
  if(!dArray_isEmpty(darray)) {
    if(index >= darray->_size) {
      dArray_pushBack(darray, value);
    } else {
      dArray_pushBack(darray, darray->_arr[darray->_size-1]);
      for(int i = darray->_size-2; i>index; i--) {
        dArray_setAt(darray, i, darray->_arr[i-1]);
      }
      dArray_setAt(darray, index, value);
    }
  }
}

void dArray_removeAt(DynamicArray *darray, unsigned index) {
  if(!dArray_isEmpty(darray)) {
    if(index >= darray->_size) {
      dArray_popBack(darray);
    } else {
      for(int i = index; i<darray->_size-1; i++) {
        dArray_setAt(darray, i, darray->_arr[i+1]);
      }
      dArray_popBack(darray);
    }
  }
}

int main() {
  DynamicArray miripVector;
  dArray_init(&miripVector);
  for(int i = 0; i<10; i++) {
    dArray_pushBack(&miripVector, i+1);
    // printf("%d ", dArray_back(&miripVector));
  }
  printf("\n");
  dArray_insertAt(&miripVector, 10, 10);
  dArray_removeAt(&miripVector, 4);
  for(int i = 0; i < miripVector._size; i++){
    printf("%d ", dArray_getAt(&miripVector, i));
  }
}