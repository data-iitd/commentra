
#include <stdio.h> // Include the standard input/output library

// Function to calculate the sum of the digits of an integer 'a'
int sum(int a) {
    int ans = 0; // Initialize the sum to 0
    // Loop until 'a' is less than 10
    while (a >= 10) {
        ans += a % 10; // Add the last digit of 'a' to 'ans'
        a /= 10; // Remove the last digit from 'a'
    }
    ans += a; // Add the remaining digit (which is less than 10) to 'ans'
    return ans; // Return the total sum of digits
}

int main() {
    int N, n, ans; // Declare variables for N, n, and ans
    scanf("%d", &N); // Read an integer input from the user
    n = (N % 2 == 0)? N / 2 : (N + 1) / 2; // Determine the value of n based on whether N is even or odd
    ans = sum(1) + sum(N - 1); // Initialize ans with the sum of digits of 1 and N-1
    for (int A = 1; A <= n; A++) { // Loop through all values from 1 to n
        if (sum(A) + sum(N - A) < ans) { // Check if the sum of digits of A and N-A is less than the current ans
            ans = sum(A) + sum(N - A); // Update ans with the new minimum sum
        }
    }
    printf("%d\n", ans); // Output the minimum sum of digits found
    return 0; // Return 0 to indicate successful execution
}
