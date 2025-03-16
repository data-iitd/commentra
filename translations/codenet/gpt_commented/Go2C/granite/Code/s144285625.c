
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int ar[3*n];
    for (int i = 0; i < 3*n; i++) {
        scanf("%d", &ar[i]);
    }

    qsort(ar, 3*n, sizeof(int), cmpfunc);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[3*n-(i+1)*2];
    }

    printf("%d\n", sum);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

