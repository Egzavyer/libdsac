#pragma once
#ifndef DARRAY_H
#define DARRAY_H

#include "common.h"

typedef struct DynamicArray
{
    int *data;
    int size;
    int capacity;
} DynamicArray;

int daCreate(int cap, DynamicArray **arr);
void daFillRand(DynamicArray *arr);
int daAppend(DynamicArray *arr, int value);
int daPop(DynamicArray *arr);
int daPrint(DynamicArray *arr);
int daRemove(DynamicArray *arr, int index);
static Error daResize(DynamicArray *arr, int newSize);
int daDestroy(DynamicArray *arr);

#endif /* DARRAY_H */