

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    qsort(numbers, n, sizeof(int), cmpfunc);

    int result = 0;
    for (int i = 0; i < k; i++) {
        result += numbers[i];
    }

    printf("%d\n", result);

    free(numbers);
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

Translate the above C code to Java and end with comment "