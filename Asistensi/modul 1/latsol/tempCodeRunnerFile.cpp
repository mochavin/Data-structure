#include <bits/stdc++.h>
using namespace std;

typedef struct stackNode_t{
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t{
    StackNode *_top;
    unsigned _size;
    int min;
} Stack;

void stack_init(Stack *stack){
    stack->_top = NULL;
    stack->_size = 0;
    stack->min = INT_MAX;
}

bool stack_isEmpty(Stack *stack){
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value){
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if(newNode){
        stack->_size++;
        newNode->data = value;

        if(stack_isEmpty(stack))
            newNode->next = NULL;
        else
            newNode->next = stack->_top;
        stack->min = min(stack->min, value);
        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack){
    if(!stack_isEmpty(stack)){
        StackNode *temp = stack->_top;
        stack->_top = temp->next;
        stack->_size--;
        free(temp);
    }
}

int stack_top(Stack *stack){
    if(!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

int stack_size(Stack *stack){
    return stack->_size;
}

int main(){
    Stack tumpukan;
    stack_init(&tumpukan);
    for(int i = 100; i > 10; i--)
        stack_push(&tumpukan, i);
    cout << "min: " << tumpukan.min << endl;
    return 0;
}