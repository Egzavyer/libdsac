#pragma once
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>

int *mergeSort(int *arr, int size);
int *merge(int *L, int sL, int *R, int sR);

#endif /* MERGE_SORT_H */