#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",max(a+b,max(a-b,a*b)));

    return 0;
}

Translate the above C code to Python and end with comment "