#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct snode_t{
  int data;
  struct  snode_t *next;
} SListNode;

typedef struct slist_t {
  unsigned _size;
  SListNode *_head;
} SinglyList;

void dlist_init(SinglyList *list) {
  list->_size = 0;
  list->_head = NULL;
}

bool slist_isEmpty(SinglyList *list) {
  return (list->_head == NULL);
}

void slist_pushBack(SinglyList *list, int value) {
  SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
  if(newNode) {
    list->_size++;
    newNode->data = value;
    newNode->next = NULL;

    if(slist_isEmpty(list)){
      list->_head = newNode;
    } else {
      SListNode *tmp = list->_head;
      while(tmp->next != NULL)
        tmp = tmp->next;
      tmp->next = newNode;
    }
  }
}

void slist_pushFront(SinglyList *list, int value) {
  SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
  if(newNode) {
    list->_size++;
    newNode->data = value;

    if(slist_isEmpty(list)) 
      newNode->next = NULL;
    else 
      newNode->next = list->_head;
    list->_head = newNode;
  }
}

void slist_insertAt(SinglyList *list, int index, int value) {
  if(slist_isEmpty(list) || index >= list->_size) {
    slist_pushBack(list, value);
    return;
  }
  else if (index == 0) {
    slist_pushFront(list, value);
    return;
  }

  SListNode *newNode = (SListNode*) malloc((sizeof(SListNode)));
  if(newNode) {
    SListNode *tmp = list->_head;
    int _i = 0;

    while(tmp->next != NULL && _i < index-1) {
      tmp = tmp->next;
      _i++;
    }
      newNode->data = value;
      newNode->next = tmp->next;
      tmp->next = newNode;
      list->_size++;
  }
}

int slist_back(SinglyList *list) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    while (tmp->next != NULL) 
      tmp = tmp->next;
    return tmp->data;
  }
  return 0;
}

int slist_front(SinglyList *list) {
  if(!slist_isEmpty(list)) {
    return list->_head->data;
  }
  return 0;
}

int slist_getAt(SinglyList *list, int index) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    int _i = 0;
    while (tmp->next != NULL && _i < index) {
      tmp = tmp->next;
      _i++;
    }
    return tmp->data;
  }
  return 0;
}

void slist_popBack(SinglyList *list) {
  if(!slist_isEmpty(list)) {
    SListNode *currNode = list->_head;
    SListNode *nextNode = currNode->next;

    if(nextNode == NULL) {
      free(currNode);
      list->_head = NULL;
      return;
    }

    while (nextNode->next != NULL) {
      currNode = nextNode;
      nextNode = nextNode->next;
    }
    currNode->next = NULL;
    free(nextNode);
    list->_size--;
  }
}

void slist_popFront(SinglyList *list) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    list->_head = list->_head->next;
    free(tmp);
    list->_size--;
  }
}

void slist_remove(SinglyList *list, int value) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp, *prev;
    tmp = list->_head;

    if(tmp->data == value) {
      slist_popFront(list);
      return;
    }
    while (tmp != NULL && tmp->data != value) {
      prev = tmp;
      tmp = tmp->next;
    }

    if(tmp == NULL) return;
    prev->next = tmp->next;
    free(tmp);
    list->_size--;
  }
}

void liTambahBack(SinglyList *list, int value) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;

    while(tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->data += value;
  }
}

void forEachElement(SinglyList *list, void (*func)(int*)) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    while(tmp != NULL) {
      func(&tmp->data);
      tmp = tmp->next;
    }
  }
}

int main() {
  SinglyList a1, a2, hasil;
  dlist_init(&a1);
  dlist_init(&a2);
  dlist_init(&hasil);
  char b1[100], b2[100];
  scanf("%s %s", b1, b2);
  for(int i = 0; i < strlen(b1); i++) {
    slist_pushBack(&a1, (int) (b1[i]-'0'));
  }
  for(int i = 0; i < strlen(b2); i++) {
    slist_pushBack(&a2, (int) (b2[i]-'0'));
  }
  int mins = (a1._size < a2._size) ? a1._size : a2._size;
  for(int i = 0; i < mins+10; i++) {
    if(!slist_isEmpty(&a1) && !slist_isEmpty(&a2)){
      int tambah = 0;
      if(slist_back(&a1) + slist_back(&a2) > 9) {
        tambah = 1;
        slist_pushBack(&hasil, (slist_back(&a1) + slist_back(&a2))%10);
      } else {
        slist_pushBack(&hasil, slist_back(&a1) + slist_back(&a2));
      }
      slist_popBack(&a1);
      slist_popBack(&a2);
      if(tambah == 1) {
        if(!slist_isEmpty(&a1)) {
          liTambahBack(&a1, 1);
        } else {
          slist_pushBack(&a1, 1);
        }
      }
    }
  }
  while(!slist_isEmpty(&a1)) {
    if(slist_back(&a1) > 9){
      slist_pushBack(&hasil, slist_back(&a1)%10);
      slist_pushBack(&hasil, slist_back(&a1)/10);
    }else{
      slist_pushBack(&hasil, slist_back(&a1));
    }
    slist_popBack(&a1);
  }
  while(!slist_isEmpty(&a2)) {
    if(slist_back(&a2) > 9){
      slist_pushBack(&hasil, slist_back(&a2)%10);
      slist_pushBack(&hasil, slist_back(&a2)/10);
    }else{
      slist_pushBack(&hasil, slist_back(&a2));
    }
    slist_popBack(&a2);
  }
  for(int i = hasil._size-1; i >= 0; i--) {
    printf("%d", slist_getAt(&hasil, i));
  }
}