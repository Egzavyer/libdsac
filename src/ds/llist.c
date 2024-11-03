#include "ds/llist.h"

struct LList *llCreate(int val)
{
    LList *list = malloc(sizeof(LList));
    if (list == NULL)
    {
        printf("llCreate failed: list = NULL\n");
        return NULL;
    }
    list->head = malloc(sizeof(Node));
    if (list->head == NULL)
    {
        printf("llCreate failed: list->head = NULL\n");
        free(list);
        return NULL;
    }
    list->head->val = val;
    list->tail = list->head;
    list->head->next = NULL;
    list->length = 1;
    return list;
}

int llAdd(LList *list, int val)
{
    if (list == NULL)
    {
        printf("llAdd failed: list = NULL\n");
        return 0;
    }
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("llAdd failed: newNode = NULL\n");
        return 0;
    }

    newNode->val = val;
    newNode->next = NULL;
    list->tail->next = newNode;
    list->tail = list->tail->next;
    list->length++;
    return 1;
}

void llPrint(LList *list)
{
    if (list == NULL)
    {
        printf("llPrint failed: list = NULL\n");
        return;
    }

    Node *curr = list->head;
    for (int i = 0; i < list->length; i++)
    {
        if (i != 0)
        {
            printf(" -> %d", curr->val);
        }
        else
        {
            printf("%d", curr->val);
        }
        curr = curr->next;
    }
    printf("\n");
}

int llRemoveTail(LList *list)
{
    if (list == NULL)
    {
        printf("llRemoveTail failed: list = NULL\n");
        return 0;
    }
    else if (list->length <= 0)
    {
        printf("llRemoveTail failed: empty list\n");
        return 0;
    }

    Node *curr = list->head;
    while (curr->next != list->tail)
    {
        curr = curr->next;
    }

    free(list->tail);
    list->tail = curr;
    curr->next = NULL;
    list->length--;
    return 1;
}

int llRemoveHead(LList *list)
{
    if (list == NULL)
    {
        printf("llRemoveHead failed: list = NULL\n");
        return 0;
    }
    else if (list->length <= 0)
    {
        printf("llRemoveHead failed: empty list\n");
        return 0;
    }

    Node *curr = list->head->next;
    free(list->head);
    list->head = curr;
    list->length--;
    return 1;
}

int llRemoveAt(LList *list, int index)
{
    if (list == NULL)
    {
        printf("llRemoveAt failed: list = NULL\n");
        return 0;
    }
    else if (list->length <= 0)
    {
        printf("llRemoveAt failed: empty list\n");
        return 0;
    }
    else if (index >= list->length || index <= -2)
    {
        printf("llRemoveAt failed: index out of bounds\n");
        return 0;
    }

    if (index == 0)
    {
        llRemoveHead(list);
        return 0;
    }
    else if (index == -1 || index == (list->length - 1))
    {
        llRemoveTail(list);
        return 1;
    }

    Node *curr = list->head;
    int count = 0;
    while (count != index - 1)
    {
        curr = curr->next;
        count++;
    }
    Node *target = curr->next;
    curr->next = curr->next->next;
    free(target);
    list->length--;
    return 1;
}

int llAddAll(LList *list, int *arr, int *arrSize)
{
    if (list == NULL)
    {
        printf("llAddAll failed: list = NULL\n");
        return 0;
    }
    if (arr == NULL)
    {
        printf("llAddAll failed: arr = NULL\n");
        return 0;
    }

    for (int i = 0; i < *arrSize; i++)
    {
        llAdd(list, arr[i]);
    }
    return 1;
}

int llContains(LList *list, int *element)
{
    if (list == NULL)
    {
        printf("llContains failed: list = NULL\n");
        return 0;
    }

    Node *curr = list->head;
    while (curr != NULL)
    {
        if (curr->val == *element)
        {
            return 1;
        }
    }
    return 0;
}