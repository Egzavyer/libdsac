#include "ds/queue.h"

int qCreate(int capacity, Queue **q)
{
    Error err = SUCCESS;
    if (q == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        *q = (Queue *)malloc(sizeof(struct Queue));
        if (*q == NULL)
        {
            err = MEM_ALLOC_FAIL;
        }
        else
        {
            (*q)->data = (int *)calloc(capacity, sizeof(int));
            if ((*q)->data == NULL)
            {
                err = MEM_ALLOC_FAIL;
                free(*q);
            }
            else
            {
                (*q)->capacity = capacity;
                (*q)->size = 0;
                (*q)->front = -1;
                (*q)->rear = -1;
            }
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "qCreate failed: %s", getErrorName(&err));
    }
    return err;
}

int qEnqueue(Queue *q, int val)
{
    Error err = SUCCESS;
    if (q == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        if (q->rear >= q->capacity)
        {
            if (q->size == q->capacity)
            {
                err = OUT_OF_BOUNDS;
            }
            else
            {
                int *newData = (int *)calloc(q->capacity, sizeof(int));
                if (newData == NULL)
                {
                    err = MEM_ALLOC_FAIL;
                }
                else
                {
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
        }
        else
        {
            if (q->size == 0)
            {
                q->rear = 0;
                q->front = 0;
            }
            q->data[q->rear] = val;
            q->rear++;
            q->size++;
        }
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "qEnqueue failed: %s", getErrorName(&err));
    }
    return err;
}

int qDequeue(Queue *q)
{
    Error err = SUCCESS;
    if (q == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        if (q->size <= 0)
        {
            err = OUT_OF_BOUNDS;
        }
        else
        {
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
        }
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "qDequeue failed: %s", getErrorName(&err));
    }
    return err;
}

int qRear(Queue *q, int *res)
{
    Error err = SUCCESS;
    if (q == NULL || res == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        if (q->rear == -1)
        {
            err = OUT_OF_BOUNDS;
        }
        else
        {
            *res = q->data[q->rear - 1];
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "qRear failed: %s", getErrorName(&err));
    }
    return err;
}

int qFront(Queue *q, int *res)
{
    Error err = SUCCESS;
    if (q == NULL || res == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        if (q->front == -1)
        {
            err = OUT_OF_BOUNDS;
        }
        else
        {
            *res = q->data[q->front];
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "qFront failed: %s", getErrorName(&err));
    }
    return err;
}

int qPrint(Queue *q)
{
    Error err = SUCCESS;
    if (q == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        if (q->size == 0)
        {
            printf("[]\n");
        }
        else if (q->front == -1 || q->rear == -1)
        {
            err = OUT_OF_BOUNDS;
        }
        else
        {
            int curr = q->front;
            printf("[");
            while (curr != q->rear)
            {
                printf(" %d", q->data[curr]);
                curr++;
            }
            printf(" ]\n");
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "qPrint failed: %s", getErrorName(&err));
    }
    return err;
}

int qDestroy(Queue *q)
{
    Error err = SUCCESS;
    if (q == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        free(q->data);
        free(q);
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "qPrint failed: %s", getErrorName(&err));
    }
    return err;
}