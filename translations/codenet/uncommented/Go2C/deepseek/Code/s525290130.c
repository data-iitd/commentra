#include <stdio.h>
#include <stdlib.h>

void reva(int* b, int len) {
    for (int i = 0; i < len / 2; i++) {
        int temp = b[i];
        b[i] = b[len - 1 - i];
        b[len - 1 - i] = temp;
    }
}

int main() {
    int n, q;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int b, e;
        scanf("%d %d", &b, &e);
        reva(a + b, e - b);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}

