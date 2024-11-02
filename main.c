#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    DynamicArray *d = daCreate(4);
    daFillRand(d);
    selectionSort(d->data, d->size);
    daPrint(d);
}
