#ifndef LLIST_H
#define LLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct LList
{
    struct Node *head;
    struct Node *tail;
    int length;
} LList;

struct LList *llCreate(int val);
void llAdd(struct LList *list, int val);
void llPrint(struct LList *list);
void llRemoveTail(struct LList *list);
void llRemoveHead(struct LList *list);
void llRemoveAt(struct LList *list, int index);
void llAddAll(struct LList *list, int *arr, int *arrSize);

#endif /* LLIST_H */