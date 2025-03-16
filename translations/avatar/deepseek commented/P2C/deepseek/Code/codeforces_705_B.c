#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int c = 2;

    for (int i = 0; i < n; i++) {
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

