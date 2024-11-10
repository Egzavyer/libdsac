#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    Queue *q = qCreate(3);
    qEnqueue(q, 1);
    printf("FRONT: %d\n", qFront(q));
    printf("REAR: %d\n", qRear(q));
    qEnqueue(q, 2);
    printf("FRONT: %d\n", qFront(q));
    printf("REAR: %d\n", qRear(q));
    qEnqueue(q, 3);
    printf("FRONT: %d\n", qFront(q));
    printf("REAR: %d\n", qRear(q));
    qPrint(q);
    qDequeue(q);
    qPrint(q);
    qEnqueue(q, 4);
    qPrint(q);
    qDequeue(q);
    qPrint(q);
    qEnqueue(q, 5);
    qPrint(q);
    free(q);
    return 0;
}
