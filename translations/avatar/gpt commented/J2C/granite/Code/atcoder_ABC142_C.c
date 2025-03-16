
#include <stdio.h> // Include necessary header files
#include <stdlib.h>
#include <string.h>

int main() {
    // Declaring a static list to hold integers (not used in the current code)
    int P[100000];

    // Reading the number of elements (N) from the input
    int N;
    scanf("%d", &N);

    // Creating an array to store the mapping of integer values to their order of input
    int idorder[N+1];

    // Looping through the range from 1 to N to read N integers
    for (int i = 1; i <= N; i++) {
        // Reading an integer A from the input
        int A;
        scanf("%d", &A);
        // Storing the integer A in the array with its order of input (i)
        idorder[A] = i;
    }

    // Looping through the range from 1 to N to print the order of each integer
    for (int i = 1; i <= N; i++) {
        // Retrieving and printing the order of the integer i from the array
        printf("%d ", idorder[i]);
    }
    // Printing a newline character after the output
    printf("\n");

    return 0;
}
