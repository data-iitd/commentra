#include <stdio.h>
#include <string.h>

// Function to return the minimum of two integers
int min(int x, int y) {
    return (x < y) ? x : y; // Return the smaller of x and y
}

// Main function where the program execution begins
int main() {
<<<<<<< HEAD
    char S[100000]; // Declare a character array to hold the input string
=======
    char S[100000]; // Declare a string with a maximum size
>>>>>>> 98c87cb78a (data updated)
    scanf("%s", S); // Read the input string

    int l0 = 0, l1 = 0; // Initialize counters for '0's and '1's
    // Loop through each character in the input string
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '0') {
            l0++; // Increment the counter for '0'
        } else {
            l1++; // Increment the counter for '1'
        }
    }
    // Print the result, which is twice the minimum count of '0's or '1's
    printf("%d\n", 2 * min(l0, l1));

<<<<<<< HEAD
    return 0; // Return 0 to indicate successful execution
=======
    return 0; // Return success
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
