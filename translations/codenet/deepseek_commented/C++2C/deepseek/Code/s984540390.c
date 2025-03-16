#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants and variables
long long ans, mx, sum, mn = 1e8, cnt = 1;

int main() {
    // Input the value of h
    long long h;
    scanf("%lld", &h);

    // Loop to calculate the answer
    while (h != 1) {
        if (h % 2 != 0) {
            h--; // Decrement h if it is odd
        }
        h /= 2; // Divide h by 2
        cnt *= 2; // Double the count
        ans += cnt; // Increment the sum by the current count
    }

    // Output the final result
    printf("%lld\n", ans + 1);
}
