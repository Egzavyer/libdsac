#pragma once
#ifndef DARRAY_H
#define DARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DynamicArray
{
    int *data;
    int size;
    int capacity;
} DynamicArray;

struct DynamicArray *daCreate(int initialSize);
void daFillRand(struct DynamicArray *arr);
void daAppend(struct DynamicArray *arr, int value);
void daPop(struct DynamicArray *arr);
void daPrint(struct DynamicArray *arr);
void daRemove(struct DynamicArray *arr, int index);
static void daResize(struct DynamicArray *arr, int newSize);

#endif /* DARRAY_H */