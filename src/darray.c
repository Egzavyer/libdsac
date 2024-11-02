#include <stdio.h>
#include <stdlib.h>

#include "../include/darray.h"

struct DynamicArray *daCreate(int cap)
{
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (arr == NULL)
    {
        printf("DynamicArray malloc failed\n");
        return NULL;
    }

    arr->data = (int *)calloc(cap, sizeof(int));

    if (arr->data == NULL)
    {
        printf("DynamicArray.data calloc failed\n");
        free(arr->data);
        free(arr);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = cap;
    return arr;
}

void daAppend(struct DynamicArray *arr, int value)
{
    if (arr == NULL)
    {
        printf("daAppend failed: arr = NULL");
        return;
    }

    if (arr->size == arr->capacity)
    {
        daResize(arr, arr->capacity * 2);
    }
    arr->data[arr->size] = value;
    arr->size++;
}

void daPop(struct DynamicArray *arr)
{
    if (arr == NULL)
    {
        printf("daPop failed: arr = NULL");
        return;
    }
    else if (arr->size <= 0)
    {
        printf("daPop failed: no elements");
    }
    arr->size--;
    if (arr->size <= (int)(arr->capacity / 2))
    {
        daResize(arr, (int)(arr->capacity / 2));
    }
}

void daPrint(struct DynamicArray *arr)
{
    if (arr == NULL)
    {
        printf("daPrint failed: arr = NULL");
        return;
    }
    else if (arr->size == 0 || arr->capacity == 0)
    {
        printf("[]");
        return;
    }

    printf("[");
    for (int i = 0; i < arr->size; i++)
    {
        if (i != (arr->size - 1))
        {
            printf("%d, ", arr->data[i]);
        }
        else
        {
            printf("%d]\n", arr->data[i]);
        }
    }
}

void daResize(struct DynamicArray *arr, int newSize)
{
    if (arr == NULL)
    {
        printf("daResize failed: arr = NULL");
        return;
    }
    else if (newSize == 0)
    {
        newSize = 1;
    }
    int *newData = calloc(newSize, sizeof(arr->data[0]));
    if (newData == NULL)
    {
        printf("daAppend calloc failed\n");
        free(newData);
        return;
    }

    for (int i = 0; i < arr->size; i++)
    {
        newData[i] = arr->data[i];
    }
    arr->data = newData;
    arr->capacity = newSize;
}