#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation

// Function to get the updated scores of all points
int* getPoints(int n, int k, int l, int r, int sAll, int sk) {
    int* ans = (int*)malloc(n * sizeof(int)); // Allocating memory for the array to store updated scores

    // Filling the initial scores of all points with the value l
    for (int i = 0; i < n; i++) {
        ans[i] = l;
    }

    // Calculating the remaining score after removing the given k points and segments of length l
    sAll -= sk + (n - k) * l;

    // Removing the score of the given k points
    sk -= k * l;

    // Finding the indices of the points to be increased in the first while loop
    int idx = n - 1;
    while (sk > 0 && idx >= n - k) {
        ans[idx--]++; // Increasing the score of the current point by 1
        sk--; // Decreasing the remaining score by 1
    }

    // Finding the indices of the points to be increased in the second while loop
    while (sAll > 0) {
        idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++; // Increasing the score of the current point by 1
            sAll--; // Decreasing the remaining score by 1
        }
    }

    // Returning the updated scores of all points as an array
    return ans;
}

int main() {
    int n, k, l, r, sAll, sk; // Declaring variables for input values

    // Reading input values from the user
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk); // Reading the values

    // Calling the getPoints() function to get the updated scores of all points
    int* ans = getPoints(n, k, l, r, sAll, sk);

    // Printing the updated scores of all points
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]); // Printing each updated score followed by a space
    }

    printf("\n"); // Printing a newline after printing all scores

    free(ans); // Freeing the allocated memory for the scores array
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
