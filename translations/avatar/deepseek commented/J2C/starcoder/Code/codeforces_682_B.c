#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmpfunc);
    int c = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= c) {
            c++;
        }
    }
    printf("%d\n", c);
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

