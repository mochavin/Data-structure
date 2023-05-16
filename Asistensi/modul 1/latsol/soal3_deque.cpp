#include <bits/stdc++.h>
using namespace std;

typedef struct dnode_t {
    string data;
    struct dnode_t *prev, *next;
} DListNode;

typedef struct deque_t {
    DListNode *_head, *_tail;
    unsigned _size;
} Deque;

void deque_init(Deque *q) {
    q->_head = q->_tail = NULL;
    q->_size = 0;
}

bool deque_isEmpty(Deque *q) {
    return (q->_head == NULL && q->_tail == NULL);
}

void deque_pushFront(Deque *q, string value) {
    if(value.size() > 100) {
        cout << "error: value is too long" << endl;
        return;
    }
    DListNode *newNode = new DListNode;
    if(newNode){
        newNode->data = value;
        newNode->prev = newNode->next = NULL;
        if(deque_isEmpty(q)) {
            q->_head = q->_tail = newNode;
        } else {
            newNode->next = q->_head;
            q->_head->prev = newNode;
            q->_head = newNode;
        }
        q->_size++;
    }
}

void deque_pushBack(Deque *q, string value) {
    if(value.size() > 100) {
        cout << "error: value is too long" << endl;
        return;
    }
    DListNode *newNode = new DListNode;
    if(newNode){
        newNode->data = value;
        newNode->prev = newNode->next = NULL;
        if(deque_isEmpty(q)) {
            q->_head = q->_tail = newNode;
        } else {
            newNode->prev = q->_tail;
            q->_tail->next = newNode;
            q->_tail = newNode;
        }
        q->_size++;
    }
}

void deque_popFront(Deque *q) {
    if(deque_isEmpty(q)) return;
    DListNode *temp = q->_head;
    q->_head = q->_head->next;
    q->_size--;
    free(temp);
}

void deque_popBack(Deque *q) {
    if(deque_isEmpty(q)) return;
    DListNode *temp = q->_tail;
    q->_tail = q->_tail->prev;
    q->_size--;
    free(temp);
}

string deque_front(Deque *q) {
    if(deque_isEmpty(q)) return NULL;
    return q->_head->data;
}

string deque_back(Deque *q) {
    if(deque_isEmpty(q)) return NULL;
    return q->_tail->data;
}

int main(){
    Deque antrian;
    deque_init(&antrian);
    string str2 = "This is a very long string that should not fit in the queue.This is a very long string that should not fit in the queue.This is a very long string that should not fit in the queue.This is a very long string that should not fit in the queue.";
    deque_pushFront(&antrian, "satu");
    deque_pushFront(&antrian, "dua");
    deque_pushBack(&antrian, "tiga");
    deque_pushBack(&antrian, "empat");
    deque_pushBack(&antrian, str2);
    cout << deque_front(&antrian) << endl;
    cout << deque_back(&antrian) << endl;
    deque_popFront(&antrian);
    deque_popBack(&antrian);
    cout << deque_front(&antrian) << endl;
    cout << deque_back(&antrian) << endl;
    return 0;
}