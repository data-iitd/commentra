#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables to store the answer, maximum value, sum, minimum value, and count
    long long ans, mx, sum, mn = 1e8, cnt = 1;

    // Read the input value for h
    long long h;
    scanf("%lld", &h);

    // Loop until h becomes 1
    while (h != 1) {
        // If h is odd, decrement it by 1 to make it even
        if (h % 2 != 0) h--;
        
        // Divide h by 2
        h /= 2;

        // Double the count for each iteration
        cnt *= 2;

        // Accumulate the count into the answer
        ans += cnt;
    }

    // Output the final answer incremented by 1
    printf("%lld\n", ans + 1);

    // End of code
    return 0;
}
