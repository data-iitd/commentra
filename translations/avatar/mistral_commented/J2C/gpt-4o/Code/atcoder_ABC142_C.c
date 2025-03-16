#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <string.h> // Including string library for string manipulation

#define MAX_N 1000 // Defining a maximum size for the array

int main() { // Main function declaration
    int N; // Declaring an integer variable 'N' to store the number of elements
    int idorder[MAX_N]; // Declaring an array to store the indices of elements

    // Reading the number of elements from the user input
    scanf("%d", &N);

    // Initializing the idorder array to -1
    for (int i = 0; i < MAX_N; i++) {
        idorder[i] = -1;
    }

    // Reading the elements and storing their corresponding indices in the array
    for (int i = 1; i <= N; i++) {
        int A; // Declaring an integer variable 'A' to store the current element
        scanf("%d", &A); // Reading an element 'A' from the user input
        idorder[A] = i; // Storing the index 'i' of the element 'A' in the array
    }

    // Printing the indices of the elements in the order they were read
    for (int i = 1; i <= N; i++) {
        printf("%d ", idorder[i]); // Printing the index of the current element
    }

    printf("\n"); // Printing a newline for better output formatting
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
