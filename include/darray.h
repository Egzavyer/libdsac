#pragma once
#ifndef DARRAY_H
#define DARRAY_H

typedef struct DynamicArray
{
    int *data;
    int size;
    int capacity;
} DynamicArray;

struct DynamicArray *daCreate(int initialSize);
void daAppend(struct DynamicArray *arr, int value);
void daPop(struct DynamicArray *arr);
void daPrint(struct DynamicArray *arr);
static void daResize(struct DynamicArray *arr, int newSize);

#endif /* DARRAY_H */