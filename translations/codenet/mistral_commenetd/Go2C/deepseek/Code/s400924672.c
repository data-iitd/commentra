#include <stdio.h>

int main() {
    int r, D, x;

    scanf("%d %d %d", &r, &D, &x);

    for (int i = 1; i <= 10; i++) {
        printf("%d\n", r * x - D);
        x = r * x - D;
    }

    return 0;
}
