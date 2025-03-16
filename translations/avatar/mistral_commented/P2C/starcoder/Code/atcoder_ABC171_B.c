
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int sorted_numbers[n];
    for (int i = 0; i < n; i++) {
        sorted_numbers[i] = numbers[i];
    }
    qsort(sorted_numbers, n, sizeof(int), compare);
    int result = 0;
    for (int i = 0; i < k; i++) {
        result += sorted_numbers[i];
    }
    printf("%d", result);
    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

