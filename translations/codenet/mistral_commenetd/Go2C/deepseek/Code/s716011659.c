#include <stdio.h>
#include <math.h>
#include <limits.h>

#define INF INT_MAX

int main() {
    // Initialize variables and read input
    int n;
    scanf("%d", &n);

    int arrA[n]; // Create an array of size n to store input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrA[i]); // Read each element of the array
    }

    int cumSumA[n + 1]; // Create an array of size n+1 to store cumulative sum
    cumSumA[0] = 0; // Initialize the first element of cumulative sum array
    for (int i = 0; i < n; i++) { // Iterate through the array and calculate cumulative sum
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    // Initialize variable to store the answer
    int ans = INF; // Initialize with a large value

    // Iterate through the array to find the answer
    for (int i = 1; i < n; i++) {
        int temp = cumSumA[n] - cumSumA[i] * 2; // Calculate the difference
        if (fabs(temp) < ans) { // If the difference is smaller than the current answer
            ans = temp; // Update the answer
        }
    }

    // Print the answer
    printf("%d\n", ans);

    // End of the code
    return 0;
}

