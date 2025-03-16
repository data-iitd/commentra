#include <stdio.h>

int main() {
    int n, m;
    
    // Read two integers n and m from input
    scanf("%d %d", &n, &m);
    
    int l[n]; // Array to store the input integers
    int l2[n]; // Array to store the processed results
    int mx = 0; // Variable to store the maximum value
    int ind = 0; // Variable to store the index of the maximum value

    // Read a list of n integers from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Iterate through each element in the input list
    for (int i = 0; i < n; i++) {
        // If the current element is divisible by m, store the quotient in l2
        if (l[i] % m == 0) {
            l2[i] = l[i] / m;
        } else {
            l2[i] = l[i] / m + 1; // Store the quotient plus one in l2
        }

        // Update the maximum value and index if necessary
        if (l2[i] > mx) {
            mx = l2[i];
            ind = i; // Store the index of the maximum value
        }
    }

    // Print the index of the maximum value (1-based index)
    printf("%d\n", ind + 1);

    return 0;
}

// <END-OF-CODE>
