#include <stdio.h>

int main() {
    int a, b; // Declare variables for the two integers
    scanf("%d %d", &a, &b); // Read the two integers from input

    int tap = 0; // Initialize the tap counter
    int consent = 1; // Initialize the consent level

    while (consent < b) { // Loop until consent reaches or exceeds b
<<<<<<< HEAD
        consent += a - 1; // Increment consent by a - 1
=======
        consent = consent + a - 1; // Increment consent by a - 1
>>>>>>> 98c87cb78a (data updated)
        tap++; // Increment the tap counter
    }

    printf("%d\n", tap); // Print the number of taps needed
    return 0; // Return success
}

// <END-OF-CODE>
