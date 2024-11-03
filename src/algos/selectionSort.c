#include "algos/selectionSort.h"

void selectionSort(int *arr, int size)
{
    int currElem, minElem;
    for (int i = 0; i < size; i++)
    {
        currElem = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[currElem])
            {
                currElem = j;
            }
        }
        swap(arr, i, currElem);
    }
}

void swap(int *arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}