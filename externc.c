
#include <stdio.h>
#include <stdlib.h>
#include "externc.h"
void cFunc1()
{
    printf("externc func\n");
}

int cFunc2(int a, int b)
{
    return a + b;
}
