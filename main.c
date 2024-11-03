#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    DynamicArray *d = daCreate(5);
    daFillRand(d);
    daPrint(d);
    insertionSort(d->data, &d->size);
    daPrint(d);
}
