#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    int size = 5;
    int *arr = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (5 - i);
    }
    DynamicArray *da = daCreate(100000);
    daFillRand(da);
    da->data = mergeSort(da->data, da->size);
    daPrint(da);
    free(da);
}
