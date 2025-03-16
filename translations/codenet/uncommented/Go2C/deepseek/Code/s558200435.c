#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *b = (int*)malloc(n * sizeof(int));
    int b_size = 0;

    for (int i = 0; i < n; i++) {
        int pos = (int)(lower_bound(b, b + b_size, a[i]) - b);
        if (pos == b_size) {
            b[b_size++] = a[i];
        } else {
            b[pos] = a[i];
        }
    }

    printf("%d\n", b_size);
    free(b);
    return 0;
}

