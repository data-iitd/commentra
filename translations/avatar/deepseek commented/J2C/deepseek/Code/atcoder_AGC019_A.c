#include <stdio.h>
#include <math.h>

int main() {
    long Q, H, S, D, N;
    scanf("%ld %ld %ld %ld %ld", &Q, &H, &S, &D, &N);

    // Calculating the minimum price for one unit
    long onePrice = fmin(fmin(Q * 4, H * 2), S);

    // Conditional logic to determine the total cost
    if ((double)onePrice <= (double)D / 2) {
        printf("%ld\n", N * onePrice);
    } else {
        printf("%ld\n", (N / 2) * D + (N % 2) * onePrice);
    }

    return 0;
}
