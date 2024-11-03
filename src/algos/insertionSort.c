#include "algos/insertionSort.h"

void insertionSort(int *arr, int *size)
{
    if (arr == NULL)
    {
        printf("insertionSort failed: arr=NULL\n");
        return;
    }
    int temp, i, j;
    for (i = 1; i < *size; i++)
    {
        for (j = i; j >= 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}