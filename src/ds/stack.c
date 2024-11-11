#include "ds/stack.h"

int sCreate(int initialSize, Stack **s)
{
    Error err = SUCCESS;
    if (s == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        *s = (Stack *)malloc(sizeof(struct Stack));
        if (*s == NULL)
        {
            err = MEM_ALLOC_FAIL;
        }
        else
        {
            (*s)->data = (int *)calloc(initialSize, sizeof(int));
            if ((*s)->data == NULL)
            {
                err = MEM_ALLOC_FAIL;
                free(*s);
            }
            else
            {
                (*s)->size = 0;
                (*s)->capacity = initialSize;
                (*s)->top = NULL;
            }
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "sCreate failed: %s", getErrorName(&err));
    }
    return err;
}

int sPush(Stack *s, int val)
{
    Error err = SUCCESS;
    if (s == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        if (s->size >= s->capacity)
        {
            err = OUT_OF_BOUNDS;
        }
        else
        {
            s->data[s->size] = val;
            s->top = &s->data[s->size];
            s->size++;
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "sPush failed: %s", getErrorName(&err));
    }
    return err;
}

int sPeek(Stack *s, int *res)
{
    Error err = SUCCESS;
    if (s == NULL || res == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        if (s->size == 0)
        {
            err = OUT_OF_BOUNDS;
        }
        else
        {
            if (s->top == NULL)
            {
                err = NULL_POINTER;
            }
            else
            {
                *res = *s->top;
            }
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "sPeek failed: %s", getErrorName(&err));
    }
    return err;
}

int sPop(Stack *s)
{
    Error err = SUCCESS;
    if (s == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        if (s->size <= 0)
        {
            err = OUT_OF_BOUNDS;
        }
        else if (s->top == NULL)
        {
            err = NULL_POINTER;
        }
        else
        {
            s->size--;
            if (s->size == 0)
            {
                s->top = NULL;
            }
            else
            {
                s->top = &s->data[s->size];
            }
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "sPop failed: %s", getErrorName(&err));
    }
    return err;
}

int sPrint(Stack *s)
{
    Error err = SUCCESS;
    if (s == NULL)
    {
        err = NULL_PARAM;
    }
    else if (s->size <= 0)
    {
        printf("[]\n");
    }
    else
    {
        printf("[");
        for (int i = 0; i < s->size; i++)
        {
            printf(", %d", s->data[i]);
        }
        printf("]\n");
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "sPrint failed: %s", getErrorName(&err));
    }
    return err;
}

int sDestroy(Stack *s)
{
    Error err = SUCCESS;
    if (s == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        free(s->data);
        free(s);
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "sDestroy failed: %s", getErrorName(&err));
    }
    return err;
}