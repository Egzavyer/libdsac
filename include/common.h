#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    INT_OVERFLOW = -4,
    NULL_POINTER = -3,
    NULL_PARAM = -2,
    MEM_ALLOC_FAIL = -1,
    OUT_OF_BOUNDS = 0,
    SUCCESS = 1
} Error;

char *getErrorName(const Error *err);

#endif /* COMMON_H */