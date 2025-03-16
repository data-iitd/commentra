
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, l, r, sAll, sk; // Declaring variables to store the input values

    // Reading input values from the user
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk);

    // Creating an integer array to store the updated scores of all points
    int *ans = (int *)malloc(n * sizeof(int));

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

    // Printing the updated scores of all points
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]); // Printing each updated score followed by a space
    }

    printf("\n"); // Printing a newline after printing all scores

    free(ans); // Freeing the memory allocated for the integer array ans

    return 0;
}

