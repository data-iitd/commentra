
#include <stdio.h>
#include <stdlib.h>

int main() {
    int in[3];
    scanf("%d %d %d", &in[0], &in[1], &in[2]);
    qsort(in, 3, sizeof(int), cmpfunc);

    printf("%d\n", in[2]*10 + in[1] + in[0]);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

