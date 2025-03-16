
#include <stdio.h>
#include <stdlib.h>

#define inf 1e14

int main() {
    // Setting up logging
    // log.SetFlags(log.Lshortfile)

    // Creating a new scanner object
    int n, x;
    scanf("%d %d", &n, &x);

    // Initializing arrays
    int a[n], v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        v[i] = a[i];
    }

    // Initializing answer variable
    int ans = inf;

    // Iterating through all possible subarrays
    for (int k = 0; k < n; k++) {
        // Initializing variable to store sum of subarray elements
        int kans = 0;

        // Iterating through all elements of the subarray
        for (int i = 0; i < n; i++) {
            // Checking if current index is out of bounds for subarray
            if (i - k < 0) {
                // Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = (v[i] < a[n + i - k]? v[i] : a[n + i - k]);
            } else {
                // Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = (v[i] < a[i - k]? v[i] : a[i - k]);
            }

            // Adding current element to the sum of subarray
            kans += v[i];
        }

        // Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = (ans < kans + k * x? ans : kans + k * x);
    }

    // Printing the answer
    printf("%d\n", ans);

    return 0;
}

// -------------------------------
// Function to check if a given number is inside a given range
int in(int c, int a, int z) {
    return c >= a && c < z;
}

// Function to convert boolean value to integer
int btoi(int b) {
    if (b) {
        return 1;
    }
    return 0;
}

// Function to convert integer value to boolean
int itob(int a) {
    if (a == 0) {
        return 0;
    }
    return 1;
}

// END-OF-CODE