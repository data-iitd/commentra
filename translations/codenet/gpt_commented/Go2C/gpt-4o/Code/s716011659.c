#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a constant for a large number to represent infinity
const double inf = 10000000000.0;

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);

    // Initialize an array to hold the input values
    int *arrA = (int *)malloc(n * sizeof(int));
    // Read the input values into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrA[i]);
    }

    // Create a cumulative sum array to store the cumulative sums of arrA
    int *cumSumA = (int *)malloc((n + 1) * sizeof(int));
    cumSumA[0] = 0; // The first element is 0 (sum of zero elements)
    // Calculate the cumulative sums
    for (int i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    // Initialize the answer variable to a large value
    double ans = inf;
    // Iterate through the cumulative sums to find the minimum difference
    for (int i = 1; i < n; i++) {
        // Calculate the absolute difference between the total sum and twice the current cumulative sum
<<<<<<< HEAD
        double currentDiff = fabs(cumSumA[n] - (cumSumA[i] * 2));
        if (currentDiff < ans) {
            // Update the answer if the current difference is smaller
            ans = currentDiff;
=======
        double diff = fabs(cumSumA[n] - (cumSumA[i] * 2));
        if (diff < ans) {
            // Update the answer if the current difference is smaller
            ans = diff;
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Print the final answer as an integer
    printf("%d\n", (int)ans);

    // Free allocated memory
    free(arrA);
    free(cumSumA);

    return 0;
}

// <END-OF-CODE>
