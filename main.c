#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{

    DynamicArray *da = daCreate(4);
    daAppend(da, 1);
    daAppend(da, 2);
    daAppend(da, 3);
    daAppend(da, 4);
    daPop(da);
    daRemove(da, 1);
    daPrint(da);
    free(da);
}
