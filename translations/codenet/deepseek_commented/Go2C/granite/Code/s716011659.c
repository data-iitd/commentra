
#include <stdio.h>
#include <math.h>

#define inf 10000000000.0

int main() {
    int n;
    scanf("%d", &n); // Reading the size of the array

    int arrA[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrA[i]); // Reading the elements of the array
    }

    int cumSumA[n+1];
    cumSumA[0] = 0; // Initialize the cumulative sum array
    for (int i = 0; i < n; i++) {
        cumSumA[i+1] = cumSumA[i] + arrA[i]; // Calculate cumulative sums
    }

    double ans = inf; // Initialize the answer with a large number
    for (int i = 1; i < n; i++) {
        double diff = fabs(cumSumA[n] - cumSumA[i]*2);
        if (diff < ans) {
            ans = diff; // Update the answer if a smaller difference is found
        }
    }

    printf("%d\n", (int)ans); // Output the minimum difference

    return 0;
}
