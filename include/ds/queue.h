#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int capacity;
    int *data;
    int front;
    int rear;
} Queue;

Queue *qCreate(int initialSize);
void qEnqueue(Queue *q, int val);
int qDequeue(Queue *q);
int qRear(Queue *q);
int qFront(Queue *q);
void qPrint(Queue *q);

#endif /* QUEUE_H */