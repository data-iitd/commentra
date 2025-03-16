#include <stdio.h> // Include the standard input-output library

int main() {
    int n; // Declare an integer variable n
    scanf("%d", &n); // Read an integer n from the user
    long long ans = 0; // Initialize the variable ans to 0

    // Loop from 1 to n (inclusive)
    for (int i = 1; i <= n; i++) {
        // Calculate a value based on the current value of i and the variable n
        long long term = n / i;
        long long sum = term * (term + 1) / 2;
        ans += (long long) i * sum;
    }

    // Print the value of ans
    printf("%lld\n", ans); // Use %lld for long long type
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
