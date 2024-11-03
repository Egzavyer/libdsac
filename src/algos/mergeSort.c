#include "algos/mergeSort.h"

int *mergeSort(int *arr, int size)
{
    if (arr == NULL)
    {
        fprintf(stderr, "mergeSort failed: arr = NULL\n");
        return NULL;
    }
    if (size == 1)
    {
        return arr;
    }

    int m = size / 2;

    int *L = (int *)calloc(m, sizeof(int));
    if (L == NULL)
    {
        fprintf(stderr, "mergeSort failed: L = NULL\n");
        return NULL;
    }
    int *R = (int *)calloc((int)(size - m), sizeof(int));
    if (R == NULL)
    {
        fprintf(stderr, "mergeSort failed: R = NULL\n");
        free(L);
        return NULL;
    }

    int i;
    for (i = 0; i < m; i++)
    {
        L[i] = arr[i];
    }
    for (i = 0; i < (size - m); i++)
    {
        R[i] = arr[m + i];
    }
    L = mergeSort(L, m);
    R = mergeSort(R, (size - m));
    return merge(L, m, R, (size - m));
}

int *merge(int *L, int sL, int *R, int sR)
{
    int *res = (int *)calloc(sL + sR, sizeof(int));
    if (res == NULL)
    {
        fprintf(stderr, "mergeSort failed: res = NULL\n");
        return NULL;
    }
    int resSize = 0;
    int i = 0;
    int j = 0;

    while ((i < sL) && (j < sR))
    {
        if (L[i] < R[j])
        {
            res[resSize] = L[i];
            resSize++;
            i++;
        }
        else
        {
            res[resSize] = R[j];
            resSize++;
            j++;
        }
    }
    while ((i < sL))
    {
        res[resSize] = L[i];
        resSize++;
        i++;
    }
    while ((j < sR))
    {
        res[resSize] = R[j];
        resSize++;
        j++;
    }
    free(L);
    free(R);
    return res;
}