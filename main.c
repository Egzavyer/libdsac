#include <stdio.h>
#include <stdlib.h>
#include "./include/dsa.h"

int main()
{
    Stack *s = sCreate(4);
    sPush(s, 1);
    printf("%d", sPeek(s));
    sPrint(s);
    sPush(s, 5);
    sPush(s, 6);
    sPrint(s);
    printf("%d", sPop(s));
    sPrint(s);
}
