
#include <stdio.h>

int main() {
    // Read the integer K from input
    int K;
    scanf("%d", &K);

    // Check if K is even or divisible by 5, return -1 if true
    if (K % 2 == 0 || K % 5 == 0) {
        printf("-1\n");
        return 0;
    }

    // If K is divisible by 7, divide it by 7
    if (K % 7 == 0) {
        K /= 7;
    }

    // Multiply K by 9 as part of the calculation
    K *= 9;

    // Initialize the answer counter
    int ans = 1;

    // Calculate the remainder of 10 divided by K
    int remainder = 10 % K;

    // Loop until the remainder is 1
    while (remainder!= 1) {
        // Increment the answer counter
        ans++;
        // Update the remainder for the next iteration
        remainder = remainder * 10 % K;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}
