#include "../../include/algos/bubbleSort.h"

void bubbleSort(int *arr, int size, int order)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (order == 0)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else if (order == 1)
            {
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else
            {
                printf("Order Parameter must be 0 for Ascending or 1 for Descending\n");
                return;
            }
        }
    }
}