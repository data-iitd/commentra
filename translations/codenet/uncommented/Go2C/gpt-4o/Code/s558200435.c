#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *b = (int *)malloc(n * sizeof(int));
    int b_len = 0;

    for (int i = 0; i < n; i++) {
        int v = a[i];
        int *pos = (int *)bsearch(&v, b, b_len, sizeof(int), compare);
        if (pos == NULL) {
            b[b_len++] = v;
        } else {
            *pos = v;
        }
    }

    printf("%d\n", b_len);

    free(a);
    free(b);
    return 0;
}

// <END-OF-CODE>
