#include <stdio.h>

int main() {
    // Define the number of elements 'n' and the modulus 'm' in the list 'l'
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an array 'l' to store the elements
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]); // Read each element into the array
    }

    // Initialize an array 'l2' to store the quotient of each element in 'l' divided by 'm'
    int l2[n];

    // Iterate through each element 'i' in the array 'l'
    for (int i = 0; i < n; i++) {
        // Check if the element 'i' is divisible by 'm'
        if (l[i] % m == 0) {
            l2[i] = l[i] / m; // Append the quotient (integer division) to 'l2'
        } else {
            l2[i] = (l[i] / m) + 1; // Append the quotient plus one
        }
    }

    // Find the maximum quotient in 'l2'
    int mx = l2[0];
    for (int i = 1; i < n; i++) {
        if (l2[i] > mx) {
            mx = l2[i];
        }
    }

    // Iterate through each index 'i' from 0 to 'n-1' in the array 'l2'
    int ind = 0; // Initialize index variable
    for (int i = 0; i < n; i++) {
        // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient 'mx'
        if (l2[i] == mx) {
            ind = i; // Store the index 'i' in the variable 'ind'
        }
    }

    // Print the index 'ind' plus one (since the indices in C start from 0)
    printf("%d\n", ind + 1);

    return 0;
}
