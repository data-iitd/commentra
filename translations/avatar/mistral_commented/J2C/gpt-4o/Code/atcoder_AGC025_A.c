#include <stdio.h>

// Function to find the sum of digits of a given number
int sum(int a) {
    int ans = 0; // Initialize answer variable
    while (a >= 10) { // While number has digits greater than 0
        ans += a % 10; // Add current digit to answer
        a /= 10; // Remove current digit from number
    }
    ans += a; // Add the last digit to answer
    return ans; // Return the sum of digits
}

// Main function starts here
int main() {
    int N; // Variable to store the input number
    scanf("%d", &N); // Read the first integer from the standard input
    int n = 0; // Initialize variable to store half of the number

    // Check if the number is even or odd and calculate n accordingly
    if (N % 2 == 0) {
        n = N / 2; // If even, n is the number divided by 2
    } else {
        n = (N + 1) / 2; // If odd, n is the number divided by 2 and rounded up
    }

    // Calculate the sum of digits of 1 and the number N-1
    int ans = sum(1) + sum(N - 1);

    // Find the answer by checking all possible pairs of subarrays
    for (int A = 1; A <= n; A++) {
        if (sum(A) + sum(N - A) < ans) { // If the sum of digits of current subarray and its complement is less than the current answer
            ans = sum(A) + sum(N - A); // Update the answer if a new pair is found with a greater sum
        }
    }

    // Print the answer
    printf("%d\n", ans);
    return 0; // Return success
}

// <END-OF-CODE>
