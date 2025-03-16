#include <stdio.h>

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int solve() {
    int K = readInt();

    // Check if K is even or divisible by 5, return -1 if true
    if (K % 2 == 0 || K % 5 == 0) 
        return -1;

    // If K is divisible by 7, divide it by 7
    if (K % 7 == 0) 
        K /= 7;

    // Multiply K by 9 as part of the calculation
    K *= 9;

    // Initialize the answer counter
    int ans = 1;

    // Calculate the remainder of 10 divided by K
    int remainder = 10 % K;

    // Loop until the remainder is 1
    while (remainder != 1) {
        // Increment the answer counter
        ans++;
        // Update the remainder for the next iteration
        remainder = remainder * 10 % K;
    }

    // Return the final answer
    return ans;
}

int main() {
    // Solve the problem and print the result
    printf("%d\n", solve());
    return 0;
}

// <END-OF-CODE>
