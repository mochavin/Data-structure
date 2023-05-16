#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 101

typedef struct snode_t{
  char data;
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

void slist_pushBack(SinglyList *list, char value) {
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

void slist_pushFront(SinglyList *list, char value) {
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

char slist_back(SinglyList *list) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    while (tmp->next != NULL) 
      tmp = tmp->next;
    return tmp->data;
  }
}

char slist_front(SinglyList *list) {
  if(!slist_isEmpty(list)) {
    return list->_head->data;
  }
}

char slist_getAt(SinglyList *list, int index) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    int _i = 0;
    while (tmp->next != NULL && _i < index) {
      tmp = tmp->next;
      _i++;
    }
    return tmp->data;
  }
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

int slist_remove(SinglyList *list, char value) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp, *prev;
    tmp = list->_head;

    if(tmp->data == value) {
      slist_popFront(list);
      return 0;
    }
    while (tmp != NULL && tmp->data != value) {
      prev = tmp;
      tmp = tmp->next;
    }

    if(tmp == NULL) return -1;
    prev->next = tmp->next;
    free(tmp);
    list->_size--;
  }
  return 0;
}

int main() {
  SinglyList a1, a2;
  dlist_init(&a1);
  dlist_init(&a2);
  char s1[100], s2[100];
  scanf("%s%s", &s1, &s2);
  int n1 = strlen(s1);
  int n2 = strlen(s2);
  // for(int i = 0; i < n1; i++) {
  //   slist_pushBack(&a1, s1[i]);
  // }
  for(int i = 0; i < n2; i++) {
    slist_pushBack(&a2, s2[i]);
    // printf("%c",slist_back(&a2));
  }
  int i = 0;
  while(!slist_isEmpty(&a2) && i < n1) {
    int si = a2._size;
    for(int j = 0; j < si; j++) {
      if(s1[i] == slist_getAt(&a2, j)) {
        // printf("%c\n", s1[i]);
        slist_remove(&a2, s1[i]);
        break; 
      }
    }
    if(si == a2._size) break;
    // printf("%d", a2._size);
    i++;
  }


  if(slist_isEmpty(&a2) && i == n1) {
    printf("YES");
  } else {
    printf("NO");
  }
  
}