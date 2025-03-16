
###
# Code
###

# Include the necessary header file
#include <stdio.h>

// Define the number of elements 'n' and the modulus'm' in the list 'l'
int n, m;

// Define the list 'l' and the list 'l2' to store the quotient of each element in 'l' divided by'm'
int l[100000], l2[100000];

// Define the maximum quotient'mx' and the index 'ind'
int mx, ind;

int main() {
    // Read the number of elements 'n' and the modulus'm' from the user
    scanf("%d %d", &n, &m);

    // Read the elements of the list 'l' from the user
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Iterate through each element 'i' in the list 'l'
    for (int i = 0; i < n; i++) {
        // Check if the element 'i' is divisible by'm'. If yes, store the quotient (integer division) in 'l2'. If not, store the quotient plus one.
        if (l[i] % m == 0) {
            l2[i] = l[i] / m;
        } else {
            l2[i] = l[i] / m + 1;
        }
    }

    // Find the maximum quotient in 'l2'
    mx = l2[0];
    for (int i = 1; i < n; i++) {
        if (l2[i] > mx) {
            mx = l2[i];
        }
    }

    // Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
    for (int i = 0; i < n; i++) {
        // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient'mx'. If yes, store the index 'i' in the variable 'ind'.
        if (l2[i] == mx) {
            ind = i;
        }
    }

    // Print the index 'ind' plus one (since the indices in C start from 0)
    printf("%d\n", ind + 1);

    // End the program
    return 0;
}
