

#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library

int main() {
    int n; // Declare an integer variable 'n' to store the number of elements
    scanf("%d", &n); // Read the number of elements (n) from the user using scanf function

    int a[n]; // Declare an array 'a' of size n to store the elements
    int r = 0; // Declare an integer variable 'r' to store the result of XOR operation

    // Read the elements of the array 'a' from the user and perform XOR operation on each element
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r ^= a[i];
    }

    // Print the result of XOR operation for each element in the array 'a'
    for (int i = 0; i < n; i++) {
        if (i!= 0) printf(" "); // Print a space before each element except the first one
        printf("%d", r ^ a[i]); // Print the result of XOR operation for each element
    }

    return 0; // Return 0 to indicate successful execution of the program
}

