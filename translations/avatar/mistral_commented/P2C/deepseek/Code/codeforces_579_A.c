#include <stdio.h>
#include <math.h>

int main() {
    int n, x = 1;
    scanf("%d", &n);

    while (1) {
        if (floor(log2(n)) == log2(n)) {
            break;
        }
        x++;
        n -= pow(2, (int)log2(n));
    }

    printf("%d\n", x);
    return 0;
}
