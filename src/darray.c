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
        printf("daAppend failed: arr = NULL\n");
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
        printf("daPop failed: arr = NULL\n");
        return;
    }
    else if (arr->size <= 0)
    {
        printf("daPop failed: no elements\n");
    }
    arr->size--;
    if (arr->size <= (int)(arr->capacity / 2))
    {
        daResize(arr, (int)(arr->capacity / 2));
    }
}

void daRemove(struct DynamicArray *arr, int index)
{
    if (arr == NULL)
    {
        printf("daRemove failed: arr = NULL\n");
        return;
    }
    else if (index >= arr->size || index <= -2)
    {
        printf("daRemove failed: index out of bounds\n");
        return;
    }

    if (index == -1)
    {
        daPop(arr);
    }

    if (arr->size - 1 <= (int)(arr->capacity / 2))
    {
        arr->capacity = (int)(arr->capacity / 2);
    }

    int *newData = calloc(arr->size, sizeof(arr->data[0]));
    if (newData == NULL)
    {
        printf("daRemove failed: newData = NULL\n");
        free(newData);
        return;
    }

    int newDataSize = 0;
    for (int i = 0; i < arr->size; i++)
    {
        if (i != index)
        {
            newData[newDataSize] = arr->data[i];
            newDataSize++;
        }
    }
    arr->size--;
    free(arr->data);
    arr->data = newData;
}

void daPrint(struct DynamicArray *arr)
{
    if (arr == NULL)
    {
        printf("daPrint failed: arr = NULL\n");
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
        printf("daResize failed: arr = NULL\n");
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
        return;
    }

    for (int i = 0; i < arr->size; i++)
    {
        newData[i] = arr->data[i];
    }
    free(arr->data);
    arr->data = newData;
    arr->capacity = newSize;
}