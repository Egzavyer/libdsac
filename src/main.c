#include <stdio.h>
#include <stdlib.h>
#include "../include/darray.h"

int main()
{

    DynamicArray *arr = daCreate(5);
    int i;
    for (i = 0; i < 6; i++)
    {
        daAppend(arr, i + 1);
        printf("Size: %d\n", arr->size);
        printf("Capacity: %d\n", arr->capacity);
        daPrint(arr);
    }
    for (i = 0; i < 6; i++)
    {
        daPop(arr);
        printf("Size: %d\n", arr->size);
        printf("Capacity: %d\n", arr->capacity);
        daPrint(arr);
    }

    return 0;
}
