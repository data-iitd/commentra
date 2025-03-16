
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i, sum = 0;
    int *a;

    // This line takes two integers, n and k, as input from the user.
    scanf("%d %d", &n, &k);

    // This line creates an array of n integers.
    a = (int*)malloc(n * sizeof(int));

    // This line takes n integers as input from the user and stores them in the array a.
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // This line sorts the array a in ascending order.
    qsort(a, n, sizeof(int), cmpfunc);

    // This line prints the sum of the first k smallest numbers from the array a.
    for (i = 0; i < k; i++) {
        sum += a[i];
    }
    printf("%d", sum);

    // This line frees the memory allocated for the array a.
    free(a);

    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

