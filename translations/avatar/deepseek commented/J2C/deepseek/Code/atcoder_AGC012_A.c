#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int size = 3 * n;
    int array[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    qsort(array, size, sizeof(int), compare);

    int head = size - 2;
    long res = 0;

    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }

    printf("%ld\n", res);

    return 0;
}
