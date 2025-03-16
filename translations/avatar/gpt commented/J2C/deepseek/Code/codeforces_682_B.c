#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int list[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    qsort(list, n, sizeof(int), compare);

    int c = 1;
    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }

    printf("%d\n", c);

    return 0;
}
