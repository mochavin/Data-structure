#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LEN 101

typedef struct dynamicarr_t {
  char **_arr;
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

void dArray_pushBack(DynamicArray *darray, const char *value)
{
    if (darray->_size + 1 >= darray->_capacity) {
        darray->_capacity *= 2;
        char **newArr = (char**) malloc(sizeof(char*) * darray->_capacity);
        if (newArr == NULL) {
            printf("Memory allocation error\n");
            exit(1);
        }

        for (unsigned it=0; it < darray->_size; ++it) {
          newArr[it] = (char*) malloc(sizeof(char) * MAX_LEN);
          if(newArr[it] == NULL) {
            printf("Memory allocation error\n");
            exit(1);
          }
          strcpy(newArr[it], darray->_arr[it]);
          free(darray->_arr[it]);
        }
        char **oldArray = darray->_arr;
        free(oldArray);
        darray->_arr = newArr;
    }
    darray->_arr[darray->_size++] = (char*) malloc(sizeof(char) * MAX_LEN);
    if(darray->_arr[darray->_size-1] == NULL) {
      printf("Memory allocation error\n");
      exit(1);
    }
    strcpy(darray->_arr[darray->_size-1], value);
}


void dArray_popBack(DynamicArray *darray) {
  if(!dArray_isEmpty(darray)) {
    free(darray->_arr[darray->_size-1]);
    darray->_size--;
  }
}

char *dArray_back(DynamicArray *darray) {
  if(!dArray_isEmpty(darray)) {
    return darray->_arr[darray->_size - 1];
  }
  return NULL;
}

char *dArray_front(DynamicArray *darray) {
  if(!dArray_isEmpty(darray))
    return darray->_arr[0];
  return NULL;
}

void dArray_setAt(DynamicArray *darray, unsigned index, const char *value) {
  if(!dArray_isEmpty(darray)) {
    if(index >= darray->_size) 
      strcpy(darray->_arr[darray->_size-1], value);
    else
      strcpy(darray->_arr[index], value);
  }
}

char *dArray_getAt(DynamicArray *darray, unsigned index) {
  if(!dArray_isEmpty(darray)) {
    if(index >= darray->_size)
      return dArray_back(darray);
    else
      return darray->_arr[index];
  }
  return NULL;
}

void dArray_insertAt(DynamicArray *darray, unsigned index, const char *value) {
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

void dArray_clear(DynamicArray *darray) {
  if(!dArray_isEmpty(darray)) {
    for(int i = 0; i<darray->_size; i++) {
      free(darray->_arr[i]);
    }
    free(darray->_arr);
    darray->_size = 0;
    darray->_capacity = 1;
  }
}

int main(){
  DynamicArray miripVector;
  dArray_init(&miripVector);
  for(int i = 0; i<10; i++) {
    dArray_pushBack(&miripVector, "tes");
  }
  dArray_setAt(&miripVector, 5, "tes2");
  dArray_insertAt(&miripVector, 2, "tes3");
  dArray_removeAt(&miripVector, 3);
  printf("%s\n", dArray_back(&miripVector));
  printf("%s\n", dArray_front(&miripVector));
  // dArray_clear(&miripVector);
  for(int i = 0; i < miripVector._size; i++) {
    printf("%d %s\n",i+1 , dArray_getAt(&miripVector, i));
  }
  printf("\n");
}