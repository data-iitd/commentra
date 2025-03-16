#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Main function is the entry point of the program
int main() {
    // Initialize an integer array named in with a length of 3
    int in[3];

    // Use scanf to read three integers from the standard input and store them in the array in
    scanf("%d %d %d", &in[0], &in[1], &in[2]);

    // Sort the integers in ascending order using qsort function
    qsort(in, 3, sizeof(int), compare);

    // Multiply the last integer by 10 and add the second last and the last integer
    // Then print the result using printf
    printf("%d\n", in[2] * 10 + in[1] + in[0]);

    return 0;
}

// <END-OF-CODE>
