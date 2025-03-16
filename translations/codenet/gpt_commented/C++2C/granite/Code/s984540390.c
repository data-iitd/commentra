
#include <stdio.h>

int main() {
    // Read the input value for h
    int h;
    scanf("%d", &h);

    // Initialize variables to store the answer, maximum value, sum, minimum value, and count
    int ans = 0, mx = 0, sum = 0, mn = 1e8, cnt = 1;

    // Loop until h becomes 1
    while (h!= 1) {
        // If h is odd, decrement it by 1 to make it even
        if (h % 2!= 0) h--;
        
        // Divide h by 2
        h /= 2;

        // Double the count for each iteration
        cnt *= 2;

        // Accumulate the count into the answer
        ans += cnt;
    }

    // Output the final answer incremented by 1
    printf("%d\n", ans + 1);
}


