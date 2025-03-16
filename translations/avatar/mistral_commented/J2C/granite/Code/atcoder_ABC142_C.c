
#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for dynamic memory allocation

int main() { // Main function declaration
    int N; // Declare an integer variable 'N' to store the number of elements

    // Read the number of elements from the user input
    scanf("%d", &N);

    int *idorder = (int *)malloc(N * sizeof(int)); // Dynamically allocate memory for an array 'idorder' of size 'N'

    // Read the elements and store their corresponding indices in the array
    for (int i = 0; i < N; i++) {
        int A; // Declare an integer variable 'A' to store the current element
        scanf("%d", &A); // Read the current element from the user input
        idorder[A - 1] = i + 1; // Store the index 'i + 1' of the current element in the array 'idorder'
    }

    // Print the indices of the elements in the order they were read
    for (int i = 0; i < N; i++) {
        printf("%d ", idorder[i]); // Print the index of the current element
    }

    free(idorder); // Free the dynamically allocated memory for the array 'idorder'

    return 0; // Return 0 to indicate successful execution of the program
}
