#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int c = 0;

    for (int i = 0; i < 2; i++) {
        c += (a > b) ? a : b;
        if (a > b) {
            a--;
        } else {
            b--;
        }
    }

    printf("%d\n", c);
    return 0;
}

