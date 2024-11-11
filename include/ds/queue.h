#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

typedef struct Queue
{
    int size;
    int capacity;
    int *data;
    int front;
    int rear;
} Queue;

int qCreate(int capacity, Queue **q);
int qEnqueue(Queue *q, int val);
int qDequeue(Queue *q);
int qRear(Queue *q, int *res);
int qFront(Queue *q, int *res);
int qPrint(Queue *q);
int qDestroy(Queue *q);
#endif /* QUEUE_H */