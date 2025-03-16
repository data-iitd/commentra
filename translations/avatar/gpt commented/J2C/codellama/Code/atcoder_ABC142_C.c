#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Declaring a static list to hold integers (not used in the current code)
static int *P;

int main(int argc, char *argv[]) {
    // Creating a Scanner object to read input from the console
    int N;
    scanf("%d", &N);
    
    // Creating a HashMap to store the mapping of integer values to their order of input
    int *idorder = (int *)malloc(N * sizeof(int));

    // Looping through the range from 1 to N to read N integers
    for (int i = 1; i <= N; i++) {
        // Reading an integer A from the input
        int A;
        scanf("%d", &A);
        // Storing the integer A in the map with its order of input (i)
        idorder[i] = A;
    }

    // Looping through the range from 1 to N to print the order of each integer
    for (int i = 1; i <= N; i++) {
        // Retrieving and printing the order of the integer i from the map
        printf("%d ", idorder[i]);
    }

    // Freeing the memory allocated for the map
    free(idorder);

    return 0;
}

