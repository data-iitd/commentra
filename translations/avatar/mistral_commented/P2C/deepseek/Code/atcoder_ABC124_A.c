#include <stdio.h>

int main() {
    int a, b, c = 0;
    scanf("%d %d", &a, &b);

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
