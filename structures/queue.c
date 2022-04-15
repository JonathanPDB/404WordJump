#include "../headers/queue.h"

Queue* createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void destroyQueue(Queue *queue){
    QueueNode *aux = queue->head;

    while(aux != NULL){
        QueueNode *tmp = aux->next;

        free(aux->data);
        free(aux);
        aux = tmp;
    }

    free(queue);
}

void enqueue(Queue *queue, void *data){
    QueueNode *new = (QueueNode *)malloc(sizeof(QueueNode));

    new->data = data;
    new->next = NULL;

    if (queue->tail != NULL)
        queue->tail->next = new;
    else
        queue->head = new;

    queue->tail = new;
}

void* dequeue(Queue *queue){
    QueueNode *aux = queue->head;
    void *data = aux->data;

    queue->head = aux->next;

    if (queue->head == NULL)
        queue->tail = NULL;

    free(aux);

    return data;
}

int isQueueEmpty(Queue *queue){
    return (queue->head == NULL);
}

