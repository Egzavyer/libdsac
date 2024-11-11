#ifndef LLIST_H
#define LLIST_H

#include "common.h"

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

int llCreate(int val, LList **list);
int llAdd(struct LList *list, int val);
int llPrint(struct LList *list);
int llRemoveTail(struct LList *list);
int llRemoveHead(struct LList *list);
int llRemoveAt(struct LList *list, int index);
int llAddAll(struct LList *list, int *arr, int *arrSize);
int llContains(LList *list, int *element, int *res);
int llDestroy(LList *list);
#endif /* LLIST_H */