#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int a;
    scanf("%d", &a);
    int sum = 0;
    int *s = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    qsort(s, n, sizeof(int), compare);

    for (int i = n - 1; i > n - a - 1; i--) {
        sum += s[i];
    }

    printf("%d\n", sum);
    free(s);
    return 0;
}

