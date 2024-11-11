#pragma once

#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct Stack
{
    int *data;
    int size;
    int *top;
    int capacity;
} Stack;

int sCreate(int initialSize, Stack **s);
int sPush(Stack *s, int val);
int sPeek(Stack *s, int *res);
int sPop(Stack *s);
int sPrint(Stack *s);
int sDestroy(Stack *s);

#endif /* STACK_H */