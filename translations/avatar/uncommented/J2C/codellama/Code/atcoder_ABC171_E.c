
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int r = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", r ^ a[i]);
    }
    free(a);
    return 0;
}

