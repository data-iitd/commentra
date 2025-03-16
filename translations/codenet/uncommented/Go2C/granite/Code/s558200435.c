
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *b = (int *)malloc(sizeof(int) * n);
    int b_len = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        while (x < b_len && b[x] < a[i]) {
            x++;
        }
        if (x == b_len) {
            b[b_len] = a[i];
            b_len++;
        } else {
            b[x] = a[i];
        }
    }

    printf("%d\n", b_len);

    free(a);
    free(b);

    return 0;
}
