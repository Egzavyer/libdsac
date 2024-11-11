#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    Queue *q;
    printf("%d\n", qCreate(5, &q));
    return 0;
}
