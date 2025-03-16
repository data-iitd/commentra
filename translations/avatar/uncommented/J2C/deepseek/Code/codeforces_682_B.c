#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int* list = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    qsort(list, n, sizeof(int), (int (*)(const void*, const void*))compare);
    int c = 1;
    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }
    printf("%d\n", c);
    free(list);
    return 0;
}

int compare(const int* a, const int* b) {
    return (*a - *b);
}

