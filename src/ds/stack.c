#include "ds/stack.h"

Stack *sCreate(int initialSize)
{
    Stack *s = (Stack *)malloc(sizeof(struct Stack));
    if (s == NULL)
    {
        fprintf(stderr, "sCreate failed: s = NULL\n");
        return NULL;
    }
    s->arr = daCreate(initialSize);
    if (s->arr == NULL)
    {
        fprintf(stderr, "sCreate failed: s->arr = NULL\n");
        free(s);
        return NULL;
    }
    s->size = 0;
    s->top = NULL;
    return s;
}

int sPush(Stack *s, int val)
{
    if (s == NULL)
    {
        fprintf(stderr, "sPush failed: s = NULL\n");
        return 0;
    }
    if (!daAppend(s->arr, val))
    {
        fprintf(stderr, "sPush failed: daAppend failed\n");
        return 0;
    }
    s->size++;
    if (s->size > 0)
    {
        s->top = &s->arr->data[s->size - 1];
    }
    return 1;
}

int sPeek(Stack *s)
{
    if (s == NULL)
    {
        fprintf(stderr, "sPeek failed: s = NULL\n");
    }
    else if (s->size <= 0)
    {
        fprintf(stderr, "sPeek failed: s is empty\n");
    }
    else
    {
        return *s->top;
    }
}

int sPop(Stack *s)
{
    if (s == NULL)
    {
        fprintf(stderr, "sPop failed: s = NULL\n");
    }
    else if (s->size <= 0)
    {
        fprintf(stderr, "sPop failed: s is empty\n");
    }
    int res = *s->top;
    daRemove(s->arr, -1);
    s->size--;
    if (s->size == 0)
    {
        s->top = NULL;
    }
    else
    {
        s->top = &s->arr->data[s->size - 1];
    }
    return res;
}

void sPrint(Stack *s)
{
    if (s == NULL)
    {
        fprintf(stderr, "sPrint failed: s = NULL\n");
        return;
    }

    daPrint(s->arr);
}