#pragma once

#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

#include "darray.h"

typedef struct Stack
{
    struct DynamicArray *arr;
    int size;
    int *top;
} Stack;

Stack *sCreate(int initialSize);
int sPush(Stack *s, int val);
int sPeek(Stack *s);
int sPop(Stack *s);
void sPrint(Stack *s);

#endif /* STACK_H */