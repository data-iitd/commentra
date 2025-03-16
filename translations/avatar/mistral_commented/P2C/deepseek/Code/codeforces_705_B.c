#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, number, c = 2;
    scanf("%d", &n);
    int w[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    for (int i = 0; i < n; i++) {
        number = w[i];
        if (number == 1) {
            printf("%d\n", c);
        } else if (number % 2 == 0) {
            c = 3 - c;
            printf("%d\n", c);
        } else {
            printf("%d\n", c);
        }
    }

    return 0;
}
