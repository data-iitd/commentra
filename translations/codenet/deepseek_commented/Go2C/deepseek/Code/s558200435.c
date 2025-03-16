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

    int *b = (int*)malloc(n * sizeof(int));
    int len = 0;

    for (int i = 0; i < n; i++) {
        int *pos = (int*)bsearch(&a[i], b, len, sizeof(int), compare);
        if (pos == NULL) {
            b[len++] = a[i];
        } else {
            *pos = a[i];
        }
    }

    printf("%d\n", len);

    free(a);
    free(b);
    return 0;
}
