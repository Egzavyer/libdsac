#include "ds/queue.h"

Queue *qCreate(int capacity)
{
    Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (q == NULL)
    {
        fprintf(stderr, "qCreate failed: q = NULL\n");
        return NULL;
    }
    q->data = (int *)calloc(capacity, sizeof(int));
    if (q->data == NULL)
    {
        fprintf(stderr, "qCreate failed: q->data = NULL\n");
        free(q);
        return NULL;
    }
    q->capacity = capacity;
    q->size = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

void qEnqueue(Queue *q, int val)
{
    if (q == NULL)
    {
        fprintf(stderr, "qEnqueue failed: q = NULL\n");
        exit(1);
    }
    if (q->rear >= q->capacity)
    {
        if (q->size == q->capacity)
        {
            fprintf(stderr, "qEnqueue failed: max capacity of %d has been reached\n", q->capacity);
            exit(1);
        }
        else
        {
            int *newData = (int *)calloc(q->capacity, sizeof(int));
            if (newData == NULL)
            {
                fprintf(stderr, "qEnqueu failed: newData = NULL\n");
                exit(1);
            }
            for (int i = 0; i < q->size; i++)
            {
                newData[i] = q->data[q->front + i];
            }
            free(q->data);
            q->data = newData;
            q->front = 0;
            q->rear = q->size;
        }
    }
    if (q->size == 0)
    {
        q->rear = 0;
        q->front = 0;
    }
    q->data[q->rear] = val;
    q->rear++;
    q->size++;
}

int qDequeue(Queue *q)
{
    if (q == NULL)
    {
        fprintf(stderr, "qDequeue failed: q = NULL\n");
        exit(1);
    }
    if (q->size <= 0)
    {
        fprintf(stderr, "qDequeue failed: queue is empty\n");
        exit(1);
    }
    int result = q->data[q->front];
    q->data[q->front] = 0;
    q->size--;
    if (q->size == 0)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return result;
}

int qRear(Queue *q)
{
    if (q == NULL)
    {
        fprintf(stderr, "qRear failed: q = NULL\n");
        exit(1);
    }
    if (q->rear == -1)
    {
        fprintf(stderr, "qRear failed: q->rear = NULL\n");
        exit(1);
    }
    return q->data[q->rear - 1];
}

int qFront(Queue *q)
{
    if (q == NULL)
    {
        fprintf(stderr, "qFront failed: q = NULL\n");
        exit(1);
    }
    if (q->front == -1)
    {
        fprintf(stderr, "qFront failed: q->front = NULL\n");
        exit(1);
    }
    return q->data[q->front];
}

void qPrint(Queue *q)
{
    if (q == NULL)
    {
        fprintf(stderr, "qPrint failed: q = NULL\n");
        exit(1);
    }
    if (q->front == -1 || q->rear == -1)
    {
        fprintf(stderr, "qPrint failed: q->front or q->rear = NULL\n");
        exit(1);
    }
    int curr = q->front;
    printf("[");
    while (curr != q->rear)
    {
        printf(" %d", q->data[curr]);
        curr++;
    }
    printf(" ]\n");
}