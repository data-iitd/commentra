#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);  // Read two integers n and m from input
    int l[n];  // Declare an array to store the list of integers
    int l2[n]; // Declare an array to store the results

    // Read the list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Iterate over each element in the list l
    for (int i = 0; i < n; i++) {
        if (l[i] % m == 0) {  // Check if the element is divisible by m
            l2[i] = l[i] / m;  // Store the quotient in l2
        } else {
            l2[i] = l[i] / m + 1;  // Store the quotient plus one in l2
        }
    }

    int mx = l2[0];  // Initialize mx with the first element of l2
    int ind = 0;     // Initialize index of maximum value

    // Find the maximum value in l2
    for (int i = 1; i < n; i++) {
        if (l2[i] > mx) {
            mx = l2[i];  // Update maximum value
            ind = i;     // Update index of maximum value
        }
    }

    printf("%d\n", ind + 1);  // Print the index of the maximum value plus one

    return 0;
}  // <END-OF-CODE>
