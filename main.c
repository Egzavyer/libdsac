#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    DynamicArray *d = daCreate(5);
    daAppend(d, 1);
    daAppend(d, 2);
    daAppend(d, 3);
    daAppend(d, 4);
    daAppend(d, 5);
    daRemove(d, 2);
    daPrint(d);
}
