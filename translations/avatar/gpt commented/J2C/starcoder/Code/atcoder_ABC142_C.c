#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declaring a static list to hold integers (not used in the current code)
    int P[100000];

    // Creating a Scanner object to read input from the console
    FILE *f = fopen("input.txt", "r");
    int N;
    fscanf(f, "%d", &N);

    // Creating a HashMap to store the mapping of integer values to their order of input
    int idorder[N+1];

    // Looping through the range from 1 to N to read N integers
    for (int i = 1; i <= N; i++) {
        // Reading an integer A from the input
        int A;
        fscanf(f, "%d", &A);
        // Storing the integer A in the map with its order of input (i)
        idorder[A] = i;
    }

    // Looping through the range from 1 to N to print the order of each integer
    for (int i = 1; i <= N; i++) {
        // Retrieving and printing the order of the integer i from the map
        printf("%d ", idorder[i]);
    }

    // Closing the input file
    fclose(f);

    return 0;
}
