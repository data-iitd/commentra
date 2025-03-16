#include <stdio.h>  // Include header for standard input/output functions
#include <limits.h> // Include header for limit values

int main() { // Define the main function
    long long N, X; // Declare variables to store the number of elements and the target value
    scanf("%lld %lld", &N, &X); // Read the values of N and X from the standard input

    long long ans = 0; // Initialize the answer variable
    long long min = LLONG_MAX; // Initialize the minimum value variable
    for (int i = 0; i < N; i++) { // Loop through N elements
        long long tmp; // Declare a temporary variable to store each input value
        scanf("%lld", &tmp); // Read the value into the temporary variable
        X -= tmp; // Subtract the value from X
        ans++; // Increment the answer count
        if (tmp < min) min = tmp; // Update the minimum value if the current value is smaller
    }

    ans += X / min; // Calculate the final answer by adding the quotient of X divided by the minimum value

    printf("%lld\n", ans); // Print the final answer to the standard output

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
