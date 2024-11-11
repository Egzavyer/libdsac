#include "ds/darray.h"

int daCreate(int cap, DynamicArray **arr)
{
    Error err = SUCCESS;
    if (arr == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        *arr = (DynamicArray *)malloc(sizeof(struct DynamicArray));
        if (*arr == NULL)
        {
            err = MEM_ALLOC_FAIL;
        }
        else
        {
            (*arr)->data = (int *)calloc(cap, sizeof(int));
            if ((*arr)->data == NULL)
            {
                err = MEM_ALLOC_FAIL;
                free(*arr);
            }
            else
            {
                (*arr)->size = 0;
                (*arr)->capacity = cap;
            }
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "daCreate failed: %s", getErrorName(&err));
    }
    return err;
}

void daFillRand(DynamicArray *arr)
{
    srand(time(NULL));
    for (int i = 0; i < arr->capacity; i++)
    {
        daAppend(arr, rand());
    }
}

int daAppend(DynamicArray *arr, int value)
{
    Error err = SUCCESS;
    if (arr == NULL)
    {
        err = NULL_PARAM;
    }
    else if (arr->size >= INT_MAX)
    {
        err = INT_OVERFLOW;
    }
    else
    {
        if (arr->size == arr->capacity)
        {
            err = daResize(arr, arr->capacity * 2);
        }
        arr->data[arr->size] = value;
        arr->size++;
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "daAppend failed: %s", getErrorName(&err));
    }
    return err;
}

int daPop(DynamicArray *arr)
{
    Error err = SUCCESS;
    if (arr == NULL)
    {
        err = NULL_PARAM;
    }
    else if (arr->size <= 0)
    {
        err = OUT_OF_BOUNDS;
    }
    else
    {
        arr->size--;
        if (arr->size <= (int)(arr->capacity / 2))
        {
            err = daResize(arr, (int)(arr->capacity / 2));
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "daPop failed: %s", getErrorName(&err));
    }
    return err;
}

int daRemove(DynamicArray *arr, int index)
{
    Error err = SUCCESS;
    if (arr == NULL)
    {
        err = NULL_PARAM;
    }
    else if (index >= arr->size || index <= -2)
    {
        err = OUT_OF_BOUNDS;
    }
    else
    {
        if (index == -1)
        {
            daPop(arr);
        }
        else
        {
            if (arr->size - 1 <= (int)(arr->capacity / 2))
            {
                arr->capacity = (int)(arr->capacity / 2);
            }

            int *newData = calloc(arr->size, sizeof(arr->data[0]));
            if (newData == NULL)
            {
                err = MEM_ALLOC_FAIL;
            }
            else
            {
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
        }
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "daRemove failed: %s", getErrorName(&err));
    }
    return err;
}

int daPrint(DynamicArray *arr)
{
    Error err = SUCCESS;
    if (arr == NULL)
    {
        err = NULL_PARAM;
    }
    else if (arr->size == 0 || arr->capacity == 0)
    {
        printf("[]\n");
    }
    else
    {
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

    if (err != SUCCESS)
    {
        fprintf(stderr, "daPrint failed: %s", getErrorName(&err));
    }
    return err;
}

int daResize(DynamicArray *arr, int newSize)
{
    Error err = SUCCESS;
    if (arr == NULL)
    {
        err = NULL_PARAM;
    }
    else if (newSize == 0)
    {
        newSize = 1;
    }
    else
    {
        int *newData = calloc(newSize, sizeof(arr->data[0]));
        if (newData == NULL)
        {
            err = MEM_ALLOC_FAIL;
        }
        else
        {
            for (int i = 0; i < arr->size; i++)
            {
                newData[i] = arr->data[i];
            }
            free(arr->data);
            arr->data = newData;
            arr->capacity = newSize;
        }
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "daResize failed: %s", getErrorName(&err));
    }
    return err;
}

int daDestroy(DynamicArray *arr)
{
    Error err = SUCCESS;
    if (arr == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        free(arr->data);
        free(arr);
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "daDestroy failed: %s", getErrorName(&err));
    }
    return err;
}