
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, c = 1;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int));
    for (i = 0; i < n; i++) {
        if (a[i] >= c) {
            c++;
        }
    }
    printf("%d\n", c);
    return 0;
}

