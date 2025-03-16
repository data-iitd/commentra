#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, c = 2;
    scanf("%d", &n);
    int *w = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    for (i = 0; i < n; i++) {
        if (w[i] == 1) {
            printf("%d\n", c);
        } else if (w[i] % 2 == 0) {
            c = 3 - c;
            printf("%d\n", c);
        } else {
            printf("%d\n", c);
        }
    }
    return 0;
}
