#include <stdio.h>

int main() {
    int a, b, sum = 0;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < 2; i++) {
        if (a >= b) {
            sum += a;
            a -= 1;
        } else {
            sum += b;
            b -= 1;
        }
    }
    printf("%d\n", sum);
    return 0;
}
