#include "ds/llist.h"

int llCreate(int val, LList **list)
{
    Error err = SUCCESS;
    if (list == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        *list = malloc(sizeof(LList));
        if (*list == NULL)
        {
            err = MEM_ALLOC_FAIL;
        }
        else
        {
            (*list)->head = malloc(sizeof(Node));
            if ((*list)->head == NULL)
            {
                err = MEM_ALLOC_FAIL;
                free(*list);
            }
            else
            {
                (*list)->head->val = val;
                (*list)->tail = (*list)->head;
                (*list)->head->next = NULL;
                (*list)->length = 1;
            }
        }
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "llCreate failed: %s", getErrorName(&err));
    }
    return err;
}

int llAdd(LList *list, int val)
{
    Error err = SUCCESS;
    if (list == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL)
        {
            err = MEM_ALLOC_FAIL;
        }
        else
        {
            newNode->val = val;
            newNode->next = NULL;
            list->tail->next = newNode;
            list->tail = list->tail->next;
            list->length++;
        }
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "llAdd failed: %s", getErrorName(&err));
    }
    return err;
}

int llPrint(LList *list)
{
    Error err = SUCCESS;
    if (list == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
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

    if (err != SUCCESS)
    {
        fprintf(stderr, "llPrint failed: %s", getErrorName(&err));
    }
    return err;
}

int llRemoveTail(LList *list)
{
    Error err = SUCCESS;
    if (list == NULL)
    {
        err = NULL_PARAM;
    }
    else if (list->length <= 0)
    {
        err = OUT_OF_BOUNDS;
    }
    else
    {
        Node *curr = list->head;
        while (curr->next != list->tail)
        {
            curr = curr->next;
        }

        free(list->tail);
        list->tail = curr;
        curr->next = NULL;
        list->length--;
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "llRemoveTail failed: %s", getErrorName(&err));
    }
    return err;
}

int llRemoveHead(LList *list)
{
    Error err = SUCCESS;
    if (list == NULL)
    {
        err = NULL_PARAM;
    }
    else if (list->length <= 0)
    {
        err = OUT_OF_BOUNDS;
    }
    else
    {
        Node *curr = list->head->next;
        if (list->head == list->tail)
        {
            list->tail = curr;
        }
        free(list->head);
        list->head = curr;
        list->length--;
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "llRemoveHead failed: %s", getErrorName(&err));
    }
    return err;
}

int llRemoveAt(LList *list, int index)
{
    Error err = SUCCESS;
    if (list == NULL)
    {
        err = NULL_PARAM;
    }
    else if (list->length <= 0)
    {
        err = OUT_OF_BOUNDS;
    }
    else if (index >= list->length || index <= -2)
    {
        err = OUT_OF_BOUNDS;
    }
    else
    {
        if (index == 0)
        {
            llRemoveHead(list);
        }
        else if (index == -1 || index == (list->length - 1))
        {
            llRemoveTail(list);
        }
        else
        {
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
        }
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "llRemoveAt failed: %s", getErrorName(&err));
    }
    return err;
}

int llAddAll(LList *list, int *arr, int *arrSize)
{
    Error err = SUCCESS;
    if (list == NULL)
    {
        err = NULL_PARAM;
    }
    else if (arr == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        for (int i = 0; i < *arrSize; i++)
        {
            llAdd(list, arr[i]);
        }
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "llAddAll failed: %s", getErrorName(&err));
    }
    return err;
}

int llContains(LList *list, int *element, int *res)
{
    Error err = SUCCESS;
    if (list == NULL || element == NULL || res == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        Node *curr = list->head;
        *res = -1;
        for (int i = 0; i < list->length; i++)
        {
            if (curr->val == *element)
            {
                *res = i;
            }
            curr = curr->next;
        }
    }
    if (err != SUCCESS)
    {
        fprintf(stderr, "llContains failed: %s", getErrorName(&err));
    }
    return err;
}

int llDestroy(LList *list)
{
    Error err = SUCCESS;
    if (list == NULL)
    {
        err = NULL_PARAM;
    }
    else
    {
        Node *curr = list->head;
        while (curr != NULL)
        {
            Node *next = curr->next;
            free(curr);
            curr = next;
        }
        free(list);
    }

    if (err != SUCCESS)
    {
        fprintf(stderr, "llDestroy failed: %s", getErrorName(&err));
    }
    return err;
}