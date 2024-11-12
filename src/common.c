#include "common.h"

char *getErrorName(const Error *err) {
    switch (*err) {
        case -4: {
            return "INT_OVERFLOW\n";
            break;
        }
        case -3: {
            return "NULL_POINTER\n";
            break;
        }
        case -2: {
            return "NULL_PARAM\n";
            break;
        }
        case -1: {
            return "MEM_ALLOC_FAIL\n";
            break;
        }
        case 0: {
            return "OUT_OF_BOUNDS\n";
            break;
        }
        case 1: {
            return "SUCCESS\n";
            break;
        }
        default: {
            return "UNKNOWN ERROR\n";
            break;
        }
    }
}