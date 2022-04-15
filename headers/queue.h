#ifndef GAME_QUEUE_H
#define GAME_QUEUE_H

#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

typedef struct QueueNode{
    void *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue{
    struct QueueNode *head;
    struct QueueNode *tail;
} Queue;

Queue* createQueue();

void destroyQueue(Queue *queue);

void enqueue(Queue *queue, void *data);

void* dequeue(Queue *queue);

int isQueueEmpty(Queue* queue);

#endif //GAME_QUEUE_H
