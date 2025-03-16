#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *numbers = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    qsort(numbers, n, sizeof(int), compare);

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += numbers[i];
    }

    printf("%d\n", sum);

    free(numbers);
    return 0;
}
