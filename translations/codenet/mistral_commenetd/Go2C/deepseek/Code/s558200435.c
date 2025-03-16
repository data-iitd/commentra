#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    int *b = (int*)malloc(n * sizeof(int));
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            b[j++] = a[i];
        }
    }

    free(a);
    a = NULL;

    printf("%d\n", j);

    free(b);
    b = NULL;

