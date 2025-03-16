#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

int main() {
    // Read the number of items (N) and the total amount (X)
    ll N, X;
    scanf("%lld %lld", &N, &X);

    // Initialize the answer and minimum value variables
    ll ans = 0; // Counter for the number of items processed
    ll min = 1000000000; // Initialize min to a large value

    // Process each item
    for (int i = 0; i < N; i++) {
        ll tmp; // Temporary variable to hold the current item's value
        scanf("%lld", &tmp); // Read the current item's value
        X -= tmp; // Subtract the item's value from total amount X
        ans++; // Increment the count of items processed
        if (tmp < min) min = tmp; // Update min if the current item is smaller
    }

    // Calculate how many more items can be added using the remaining amount
    ans += X / min; // Add the number of additional items that can be bought

    // Output the final answer
    printf("%lld\n", ans);

    return 0; // Indicate successful completion of the program
}

// <END-OF-CODE>
