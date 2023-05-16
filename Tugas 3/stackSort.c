#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

void sort(Stack *tumpukan1, Stack *tumpukan2) {
    int temp;
    while(!stack_isEmpty(tumpukan1)) {
        temp = stack_top(tumpukan1);
        stack_pop(tumpukan1);
        while(!stack_isEmpty(tumpukan2) && temp < stack_top(tumpukan2)) {
            stack_push(tumpukan1, stack_top(tumpukan2));
            stack_pop(tumpukan2);
        }
        stack_push(tumpukan2, temp);
    }
    while(!stack_isEmpty(tumpukan2)) {
        stack_push(tumpukan1, stack_top(tumpukan2));
        stack_pop(tumpukan2);
    }
}

void cetak(Stack *tumpukan) {
    StackNode *temp = tumpukan->_top;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack tumpukan1, tumpukan2;
    tumpukan1._top = NULL;
    tumpukan1._size = 0;
    tumpukan2._top = NULL;
    tumpukan2._size = 0;
    for(int i = 1; i <= 10; i++) {
        stack_push(&tumpukan1, i);
    }
    stack_push(&tumpukan1, 5);
    stack_push(&tumpukan1, 3);
    stack_push(&tumpukan1, 71);
    stack_push(&tumpukan1, -2);
    stack_push(&tumpukan1, 0);
    printf("sebelum diurutkan: \n");
    cetak(&tumpukan1);
    sort(&tumpukan1, &tumpukan2);
    printf("setelah diurutkan: \n");
    cetak(&tumpukan1);
    return 0;
}