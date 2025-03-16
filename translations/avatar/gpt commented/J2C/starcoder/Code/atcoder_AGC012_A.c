#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int array[3 * n];
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &array[i]);
    }
    qsort(array, 3 * n, sizeof(int), compare);
    int head = 3 * n - 2;
    long res = 0;
    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }
    printf("%ld\n", res);
    return 0;
}

