#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int sum = 0;

    for (int i = 0; i < 2; i++) {
        if (a >= b) {
            sum += a;
            a--;
        } else {
            sum += b;
            b--;
        }
    }

    printf("%d\n", sum);
    return 0;
}

