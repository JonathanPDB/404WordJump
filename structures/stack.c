#include "../headers/stack.h"

// Funcao que cria uma pilha
Stack* createStack(){
    Stack *pilha = (Stack*)malloc(sizeof(Stack));
    pilha->top = NULL;
    return pilha;
}

// Funcao que destroi uma stack
void destroyStack(Stack *stack){
    StackNode *aux = stack->top;
    while(aux != NULL){
        StackNode *tmp = aux->next;
        free(aux->data);
        free(aux); // Cuidar ordem do free
        aux = tmp;
    }
    free(stack);
}

// Funcao que insere um elemento na stack
void pushStack(Stack *stack, void *data){
    StackNode *new = (StackNode*)malloc(sizeof(StackNode));
    new->data = data;
    new->next = stack->top;
    stack->top = new;
}


// Funcao que remove um elemento da stack
void* popStack(Stack* stack){
    StackNode *aux = stack->top;
    /* Aqui assumimos que desempilha eh
    chamada apenas se a stack nao eh vazia */
    void* data = aux->data;
    stack->top = aux->next;
    free(aux);
    return data;
}

// Funcao que determina se uma stack eh vazia
int isStackEmpty(Stack *stack){
    return (stack->top == NULL);
}
