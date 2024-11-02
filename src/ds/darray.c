#include "../../include/ds/darray.h"

struct DynamicArray *daCreate(int cap)
{
    struct DynamicArray *arr = malloc(sizeof(struct DynamicArray));
    if (arr == NULL)
    {
        printf("DynamicArray malloc failed\n");
        return NULL;
    }

    arr->data = (int *)calloc(cap, sizeof(int));

    if (arr->data == NULL)
    {
        printf("DynamicArray.data calloc failed\n");
        free(arr);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = cap;
    return arr;
}

void daFillRand(struct DynamicArray *arr)
{
    srand(time(NULL));
    for (int i = 0; i < arr->capacity; i++)
    {
        daAppend(arr, rand());
    }
}

int daAppend(struct DynamicArray *arr, int value)
{
    if (arr == NULL)
    {
        printf("daAppend failed: arr = NULL\n");
        return 0;
    }

    if (arr->size == arr->capacity)
    {
        daResize(arr, arr->capacity * 2);
    }
    arr->data[arr->size] = value;
    arr->size++;
    return 1;
}

int daPop(struct DynamicArray *arr)
{
    if (arr == NULL)
    {
        printf("daPop failed: arr = NULL\n");
        return 0;
    }
    else if (arr->size <= 0)
    {
        printf("daPop failed: no elements\n");
        return 0;
    }
    arr->size--;
    if (arr->size <= (int)(arr->capacity / 2))
    {
        daResize(arr, (int)(arr->capacity / 2));
    }
    return 1;
}

int daRemove(struct DynamicArray *arr, int index)
{
    if (arr == NULL)
    {
        printf("daRemove failed: arr = NULL\n");
        return 0;
    }
    else if (index >= arr->size || index <= -2)
    {
        printf("daRemove failed: index out of bounds\n");
        return 0;
    }

    if (index == -1)
    {
        daPop(arr);
        return 1;
    }

    if (arr->size - 1 <= (int)(arr->capacity / 2))
    {
        arr->capacity = (int)(arr->capacity / 2);
        if (arr->capacity == 0)
        {
            int *newData = calloc(arr->capacity, sizeof(arr->data[0]));
        }
    }

    int *newData = calloc(arr->size, sizeof(arr->data[0]));
    if (newData == NULL)
    {
        printf("daRemove failed: newData = NULL\n");
        return 0;
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
    return 1;
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
        printf("[]\n");
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

int daResize(struct DynamicArray *arr, int newSize)
{
    if (arr == NULL)
    {
        printf("daResize failed: arr = NULL\n");
        return 0;
    }
    else if (newSize == 0)
    {
        newSize = 1;
    }
    int *newData = calloc(newSize, sizeof(arr->data[0]));
    if (newData == NULL)
    {
        printf("daResize calloc failed\n");
        return 0;
    }

    for (int i = 0; i < arr->size; i++)
    {
        newData[i] = arr->data[i];
    }
    free(arr->data);
    arr->data = newData;
    arr->capacity = newSize;
    return 1;
}