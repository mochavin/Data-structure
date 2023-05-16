#include <bits/stdc++.h>
using namespace std;

typedef struct queueNode_t {
    string data;
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode *_front, *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *q) {
    q->_front = q->_rear = NULL;
    q->_size = 0;
}

bool queue_isEmpty(Queue *q) {
    return (q->_front == NULL && q->_rear == NULL);
}

void queue_push(Queue *q, string value) {
    if(value.size() > 100) {
        cout << "error: value is too long" << endl;
        return;
    }
    QueueNode *newNode = new QueueNode;
    if(newNode){
        newNode->data = value;
        newNode->next = NULL;
        if(queue_isEmpty(q)) {
            q->_front = q->_rear = newNode;
        } else {
            q->_rear->next = newNode;
            q->_rear = newNode;
        }
        q->_size++;
    }
}

void queue_pop(Queue *q) {
    if(queue_isEmpty(q)) return;
    QueueNode *temp = q->_front;
    q->_front = q->_front->next;
    q->_size--;
    free(temp);
}

string queue_front(Queue *q) {
    if(queue_isEmpty(q)) return NULL;
    return q->_front->data;
}

int main(){
    Queue antrian;
    queue_init(&antrian);
    string str2 = "This is a very long string that should not fit in the queue.This is a very long string that should not fit in the queue.This is a very long string that should not fit in the queue.This is a very long string that should not fit in the queue.";
    queue_push(&antrian, "satu");
    queue_push(&antrian, "dua");
    queue_push(&antrian, "tiga");
    queue_push(&antrian, str2);
    cout << queue_front(&antrian) << endl;
    queue_pop(&antrian);
    cout << queue_front(&antrian) << endl;
    queue_pop(&antrian);
    cout << "ukuran queue : " << queue_front(&antrian) << endl;
    cout << antrian._size << endl;
    queue_pop(&antrian);
}