#ifndef GAME_STACK_H
#define GAME_STACK_H

#include <stdlib.h>

typedef struct StackNode{
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack{
    struct StackNode *top;
} Stack;

// Funcao que cria uma pilha
Stack* createStack();

// Funcao que destroi uma stack
void destroyStack(Stack *stack);

// Funcao que insere um elemento na stack
void pushStack(Stack *stack, void* data);

// Funcao que remove um elemento da stack
void* popStack(Stack *stack);

// Funcao que determina se uma stack eh vazia
int isStackEmpty(Stack* stack);

#endif //GAME_STACK_H
