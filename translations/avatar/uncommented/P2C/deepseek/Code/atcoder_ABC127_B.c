#include <stdio.h>
#include <math.h>

int main() {
    int r, D, x;
    scanf("%d %d %d", &r, &D, &x);
    for (int i = 2; i <= 11; i++) {
        int result = (int)(pow(r, i - 1) * (x + D / (1.0 - r)) - D / (1.0 - r));
        printf("%d\n", result);
    }
    return 0;
}
