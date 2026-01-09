#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <string.h>

#define MAXqueue 256

typedef char str256[257];

typedef struct QueueType{
    str256 items[MAXqueue];
    int head, tail, size; 
} Queue;

void createQueue(Queue *queue);
bool enqueue(Queue *queue, str256 token);
bool dequeue(Queue *queue, str256 token);
bool queueHead(Queue *queue, str256 token);
bool queueTail(Queue *queue, str256 token);
bool queueEmpty(Queue *queue);
bool queueFull(Queue *queue);

#endif