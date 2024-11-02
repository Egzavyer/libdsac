#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    LList *list = llCreate(0);
    DynamicArray *arr = daCreate(5);
    daFillRand(arr);
    llAddAll(list, arr->data, &arr->size);
    llPrint(list);
    llRemoveAt(list, list->length - 1);
    llPrint(list);
}
