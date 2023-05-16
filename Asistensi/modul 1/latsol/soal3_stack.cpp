#include <bits/stdc++.h>
using namespace std;

typedef struct stackNode_t {
    string data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *s) {
    s->_top = NULL;
    s->_size = 0;
}

bool stack_isEmpty(Stack *s) {
    return (s->_top == NULL);
}

void stack_push(Stack *s, string value) {
    if(value.size() > 100) {
        cout << "error: value is too long" << endl;
        return;
    }
    StackNode *newNode = new StackNode;
    if(newNode){
        newNode->data = value;
        if(stack_isEmpty(s)) {
            newNode->next = NULL;
        } else {
            newNode->next = s->_top;
        }
        s->_top = newNode;
        s->_size++;
    }
}

void stack_pop(Stack *s) {
    if(stack_isEmpty(s)) return;
    StackNode *temp = s->_top;
    s->_top = s->_top->next;
    s->_size--;
    free(temp);
}

string stack_top(Stack *s) {
    if(stack_isEmpty(s)) return NULL;
    return s->_top->data;
}

int main(){
    Stack tumpukan;
    stack_init(&tumpukan);
    string str2 = "This is a very long string that should not fit in the stack.This is a very long string that should not fit in the stack.This is a very long string that should not fit in the stack.This is a very long string that should not fit in the stack.";
    stack_push(&tumpukan, "satu");
    stack_push(&tumpukan, "dua");
    stack_push(&tumpukan, "tiga");
    stack_push(&tumpukan, "empat");
    stack_push(&tumpukan, str2);
    cout << stack_top(&tumpukan) << endl;
    stack_pop(&tumpukan);
    cout << "berjumlah " << tumpukan._size << endl;
    cout << stack_top(&tumpukan) << endl;
    stack_pop(&tumpukan);
    cout << stack_top(&tumpukan);
}