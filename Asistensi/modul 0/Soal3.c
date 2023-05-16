#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 1004

typedef struct snode_t{
  char data[MAX_LEN];
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

void slist_pushBack(SinglyList *list, const char *value) {
  SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
  if(newNode) {
    list->_size++;
    strcpy(newNode->data, value);
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

void slist_pushFront(SinglyList *list, const char *value) {
  SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
  if(newNode) {
    list->_size++;
    strcpy(newNode->data, value);

    if(slist_isEmpty(list)) 
      newNode->next = NULL;
    else 
      newNode->next = list->_head;
    list->_head = newNode;
  }
}

void slist_insertAt(SinglyList *list, int index, const char *value) {
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
      strcpy(newNode->data, value);
      newNode->next = tmp->next;
      tmp->next = newNode;
      list->_size++;
  }
}

const char* slist_back(SinglyList *list) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    while (tmp->next != NULL) 
      tmp = tmp->next;
    return tmp->data;
  }
  return "";
}

const char* slist_front(SinglyList *list) {
  if(!slist_isEmpty(list)) {
    return list->_head->data;
  }
  return 0;
}

const char* slist_getAt(SinglyList *list, int index) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    int _i = 0;
    while (tmp->next != NULL && _i < index) {
      tmp = tmp->next;
      _i++;
    }
    return tmp->data;
  }
  return "";
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

void slist_remove(SinglyList *list, const char* value) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp, *prev;
    tmp = list->_head;

    if(strcmp(tmp->data, value) == 0) {
      slist_popFront(list);
      return;
    }
    while (tmp != NULL && strcmp(tmp->data, value)) {
      prev = tmp;
      tmp = tmp->next;
    }

    if(tmp == NULL) return;
    prev->next = tmp->next;
    free(tmp);
    list->_size--;
  }
}

void printElement(char *elem) {
  printf("%s \n", elem);
}

void reverseEach(char *elem) {
  char tmp[MAX_LEN];
  strcpy(tmp, elem);
  int len = strlen(tmp);
  for(int i = 0; i < len; i++) {
    tmp[i] = elem[len-i-1];
  }
  strcpy(elem, tmp);
}

void forEachElement(SinglyList *list, void (*func)(char*)) {
  if(!slist_isEmpty(list)) {
    SListNode *tmp = list->_head;
    while(tmp != NULL) {
      func(tmp->data);
      tmp = tmp->next;
    }
  }
}

int main() {
  SinglyList li;
  dlist_init(&li);
  slist_pushBack(&li, "Pertama");
  slist_pushBack(&li, "Kedua");
  slist_pushBack(&li, "Ketiga");
  slist_pushBack(&li, "Keempat");
  slist_pushBack(&li, "Kelima");
  slist_pushBack(&li, "Keenam");
  slist_pushBack(&li, "Ketujuh");
  slist_pushBack(&li, "Kedelapan");
  slist_pushBack(&li, "Kesembilan");
  slist_pushBack(&li, "Kesepuluh");
  slist_remove(&li, "Ketiga");
  slist_popBack(&li);
  slist_popFront(&li);
  printf("%s ", slist_getAt(&li, 3));
  forEachElement(&li, reverseEach);
  forEachElement(&li, printElement);
  printf("\n");
}