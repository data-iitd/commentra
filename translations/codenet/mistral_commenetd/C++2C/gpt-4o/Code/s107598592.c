#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Main function starts here
int main() {
    int N; // Number of elements in the array

    // Taking input of N from the user
    scanf("%d", &N);

    // Declaring two arrays X and Y of size N
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));

    // Filling the arrays X and Y with user input
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]); // Taking input of X[i] from the user
        Y[i] = X[i]; // Assigning X[i] to Y[i]
    }

    // Sorting the array Y in ascending order
    qsort(Y, N, sizeof(int), compare);

    // Finding the middle element of sorted array Y
    int y = Y[N / 2];

    // Iterating through the array X and printing the middle element of Y based on the condition
    for (int i = 0; i < N; i++) {
        if (X[i] < Y[N / 2]) { // Checking if X[i] is less than the middle element of Y
            printf("%d\n", Y[N / 2]); // If true, print the middle element of Y
        } else { // If X[i] is greater than or equal to the middle element of Y
            printf("%d\n", Y[N / 2 - 1]); // Print the middle element of Y - 1
            break; // Exit the loop as we have found the required element
        }
    }

    // Freeing allocated memory
    free(X);
    free(Y);

    // End of main function
    return 0;
}
// <END-OF-CODE>
