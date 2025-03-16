

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; // Declare an integer variable 'n' to read the number of elements in the array 'a'

    // Read the number of elements 'n' from the standard input
    scanf("%d", &n);

    // Declare an array 'a' of size 'n' and initialize it with zeros
    long long a[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0; // Initialize the 'i'-th element of the array 'a' to zero
    }

    // Read the elements of the array 'a' from the standard input
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]); // Read the 'i'-th element of the array 'a'
    }

    // Create a copy of the array 'a' named 'abs_a' to store the absolute values of its elements
    long long abs_a[n];
    for (int i = 0; i < n; i++) {
        abs_a[i] = a[i]; // Copy the 'i'-th element of the array 'a' to the 'i'-th element of the array 'abs_a'
    }

    // Iterate through each element of the array 'abs_a' and make it positive if it's negative
    for (int i = 0; i < n; i++) {
        if (abs_a[i] < 0) { // Check if the current element is negative
            abs_a[i] = -abs_a[i]; // Make it positive by negating it
        }
    }

    // Initialize the variables 'ans' and'min' with zero and the first element of 'abs_a' respectively
    long long ans = 0, min = abs_a[0];

    // Iterate through each element of the array 'abs_a' and update the variables 'ans' and'min' accordingly
    for (int i = 0; i < n; i++) {
        ans += abs_a[i]; // Add the current element to the variable 'ans'
        if (min > abs_a[i]) { // Check if the current element is smaller than the current minimum
            min = abs_a[i]; // Update the minimum if it is
        }
    }

    // Initialize the variable 'num_negative' with zero and count the number of negative elements in the array 'a'
    int num_negative = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) { // Check if the current element is negative
            num_negative++; // Increment the counter if it is
        }
    }

    // Check if the number of negative elements is odd or even and update the variable 'ans' accordingly
    if (num_negative % 2) {
        ans -= min * 2; // Subtract twice the minimum if the number of negative elements is odd
    }

    // Print the final answer 'ans' to the standard output
    printf("%lld\n", ans);

    return 0;
}

