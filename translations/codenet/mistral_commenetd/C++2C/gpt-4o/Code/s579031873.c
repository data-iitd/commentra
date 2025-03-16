#include <stdio.h>  // Include the standard input/output header file.
#include <limits.h> // Include the limits header file for INT_MAX, etc.

typedef long long ll; // Define a new type alias for long long integers.

int main() { // Start of the main function.
    ll N, X; // Declare two long long integers named "N" and "X".

    scanf("%lld %lld", &N, &X); // Read two integers from the standard input stream and assign them to "N" and "X" respectively.

    ll ans = 0; // Initialize an integer variable named "ans" to zero.
    ll min = LLONG_MAX; // Initialize an integer variable named "min" to a large value.

    for (int i = 0; i < N; i++) { // Start of a for loop that iterates from 0 to N-1.
        ll tmp; // Declare a long long integer variable named "tmp".

        scanf("%lld", &tmp); // Read an integer from the standard input stream and assign it to "tmp".

        X -= tmp; // Subtract "tmp" from "X".
        ans++; // Increment "ans" by 1.

        if (tmp < min) min = tmp; // If "tmp" is smaller than the current minimum value, update the minimum value.
    }

    ans += X / min; // Divide "X" by the minimum value and add the quotient to "ans".

    printf("%lld\n", ans); // Output the value of "ans" to the standard output stream.

    return 0; // End of the main function with a return value of 0.
}

// <END-OF-CODE>
