#include <bits/stdc++.h>
using namespace std;

typedef struct pqueueNode_t {
    string data;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *q) {
    q->_top = NULL;
    q->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *q) {
    return (q->_top == NULL);
}

void pqueue_push(PriorityQueue *q, string value) {
    if(value.size() > 100) {
        cout << "error: value is too long" << endl;
        return;
    }
    PQueueNode *newNode = new PQueueNode;
    if(newNode){
        newNode->data = value;
        newNode->next = NULL;
        if(pqueue_isEmpty(q)) {
            q->_top = newNode;
        } else {
            PQueueNode *curr = q->_top;
            PQueueNode *prev = NULL;
            while(curr && curr->data < value) {
                prev = curr;
                curr = curr->next;
            }
            if(prev == NULL) {
                newNode->next = q->_top;
                q->_top = newNode;
            } else {
                newNode->next = curr;
                prev->next = newNode;
            }
        }
        q->_size++;
    }
}

void pqueue_pop(PriorityQueue *q) {
    if(!pqueue_isEmpty(q)) {
        PQueueNode *temp = q->_top;
        q->_top = q->_top->next;
        delete temp;
        q->_size--;
    }
}

string pqueue_top(PriorityQueue *q) {
    if(!pqueue_isEmpty(q)) {
        return q->_top->data;
    }
    return "error: empty queue";
}

void pqueue_print(PriorityQueue *q) {
    if(!pqueue_isEmpty(q)) {
        PQueueNode *curr = q->_top;
        while(curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int main() {
    PriorityQueue q;
    pqueue_init(&q);
    pqueue_push(&q, "ak");
    pqueue_push(&q, "al");
    pqueue_push(&q, "am");
    pqueue_push(&q, "an");
    pqueue_push(&q, "ao");
    pqueue_push(&q, "ap");
    pqueue_push(&q, "aq");
    pqueue_push(&q, "ar");
    pqueue_push(&q, "e");
    pqueue_push(&q, "f");
    pqueue_push(&q, "g");
    pqueue_push(&q, "h");
    pqueue_push(&q, "as");
    pqueue_push(&q, "at");
    pqueue_push(&q, "au");
    pqueue_push(&q, "av");
    pqueue_push(&q, "a");
    pqueue_push(&q, "b");
    pqueue_push(&q, "c");
    pqueue_push(&q, "d");
    pqueue_push(&q, "i");
    pqueue_push(&q, "z");
    pqueue_push(&q, "p");
    pqueue_push(&q, "q");
    pqueue_push(&q, "r");
    pqueue_push(&q, "aa");
    pqueue_push(&q, "ab");
    pqueue_push(&q, "j");
    pqueue_push(&q, "k");
    pqueue_push(&q, "l");
    pqueue_push(&q, "m");
    pqueue_push(&q, "n");
    pqueue_push(&q, "o");
    pqueue_push(&q, "s");
    pqueue_push(&q, "ag");
    pqueue_push(&q, "t");
    pqueue_push(&q, "u");
    pqueue_push(&q, "v");
    pqueue_push(&q, "ad");
    pqueue_push(&q, "ae");
    pqueue_push(&q, "x");
    pqueue_push(&q, "y");
    pqueue_push(&q, "ac");
    pqueue_push(&q, "af");
    pqueue_push(&q, "w");
    pqueue_push(&q, "ah");
    pqueue_push(&q, "ai");
    pqueue_push(&q, "aj");
    pqueue_push(&q, "aw");
    pqueue_print(&q);
    pqueue_pop(&q);
}