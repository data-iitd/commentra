#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation
#include <string.h> // Including string library for string manipulation

#define MAX_SIZE 1001 // Defining the maximum size for the frequency array

// Function to solve the problem
void solve() {
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements from input

    int array[MAX_SIZE] = {0}; // Creating an array to store the frequency of each element, initialized to 0

    // Loop to read and store the elements in the array
    for (int i = 0; i < n; i++) {
        int index;
        scanf("%d", &index); // Reading the element
        array[index]++; // Incrementing the frequency of the element at the given index
    }

    int countMax = -1; // Initializing the maximum frequency to -1

    // Loop to find the maximum frequency
    for (int i = 1; i < MAX_SIZE; i++) {
        if (countMax < array[i]) {
            countMax = array[i]; // Updating the maximum frequency
        }
    }

    // Checking if the number of elements is even
    if (n % 2 == 0) {
        // If the maximum frequency is less than or equal to half of the number of elements
        if (countMax <= n / 2) {
            printf("YES\n"); // Printing "YES" as the output
        } else {
            printf("NO\n"); // Else printing "NO" as the output
        }
    } else { // If the number of elements is odd
        // If the maximum frequency is less than or equal to half of the number of elements plus one
        if (countMax <= n / 2 + 1) {
            printf("YES\n"); // Printing "YES" as the output
        } else {
            printf("NO\n"); // Else printing "NO" as the output
        }
    }
}

// Main function to start the program
int main() {
    solve(); // Calling the solve function to solve the problem
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
