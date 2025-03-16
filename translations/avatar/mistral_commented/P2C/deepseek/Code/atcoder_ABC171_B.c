#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    qsort(numbers, n, sizeof(int), compare);

    int result = 0;
    for (int i = 0; i < k; i++) {
        result += numbers[i];
    }

    printf("%d\n", result);

    return 0;
}
