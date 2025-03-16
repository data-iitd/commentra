#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000 // Define a maximum size for the input

int main() {
    int N;
    // Array to hold the order of input for integers
    int idorder[MAX_N] = {0};

    // Reading the number of elements (N) from the input
    scanf("%d", &N);

    // Looping through the range from 1 to N to read N integers
    for (int i = 1; i <= N; i++) {
        int A;
        // Reading an integer A from the input
        scanf("%d", &A);
        // Storing the order of input (i) in the idorder array at index A
        idorder[A] = i;
    }

    // Looping through the range from 1 to N to print the order of each integer
    for (int i = 1; i <= N; i++) {
        // Printing the order of the integer i from the idorder array
        printf("%d ", idorder[i]);
    }

    return 0;
}

// <END-OF-CODE>
