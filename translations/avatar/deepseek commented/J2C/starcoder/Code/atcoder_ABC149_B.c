#include <stdio.h>
#include <stdlib.h>

int main()
{
    long A, B, K, x, y;
    scanf("%ld %ld %ld", &A, &B, &K);
    x = A - K;
    if (x < 0) {
        y = B + x;
        x = 0;
        if (y < 0) {
            y = 0;
        }
    }
    printf("%ld %ld\n", x, y);
    return 0;
}
