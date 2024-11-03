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
int llAdd(struct LList *list, int val);
void llPrint(struct LList *list);
int llRemoveTail(struct LList *list);
int llRemoveHead(struct LList *list);
int llRemoveAt(struct LList *list, int index);
int llAddAll(struct LList *list, int *arr, int *arrSize);
int llContains(LList *list, int *element);
#endif /* LLIST_H */