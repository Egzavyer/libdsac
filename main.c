#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    DynamicArray *d = daCreate(4);
    daFillRand(d);
    daPrint(d);
    bubbleSort(d->data, d->size, 0);
    daPrint(d);
    bubbleSort(d->data, d->size, 1);
    daPrint(d);
}
