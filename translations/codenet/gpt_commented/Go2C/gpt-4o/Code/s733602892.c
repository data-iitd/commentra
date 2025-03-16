#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

// Function to read an integer from input
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read an array of integers from input
void readInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = readInt();
    }
}

int main() {
    // Read the number of elements N and the threshold K
    int N = readInt();
    int K = readInt();
    
    // Allocate memory for the two arrays
    int *As = (int *)malloc(N * sizeof(int));
    int *Fs = (int *)malloc(N * sizeof(int));
    
    // Read the two slices of integers As and Fs
    readInts(As, N);
    readInts(Fs, N);

    // Sort the As array in ascending order
    qsort(As, N, sizeof(int), compare);
    // Sort the Fs array in descending order
    qsort(Fs, N, sizeof(int), compare);
    
    // Create an array to hold the scores calculated from As and Fs
    int *scores = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        // Calculate the score for each pair of As and Fs
        scores[i] = As[i] * Fs[i];
    }
    
    // Sort the scores in descending order
    qsort(scores, N, sizeof(int), compare);

    // Initialize binary search boundaries
    int ok = scores[0]; // The maximum possible score
    int ng = -1;        // The minimum possible score

    // Perform binary search to find the maximum score that can be achieved
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2; // Calculate the midpoint of the current range

        bool isOK = true; // Flag to check if the current mid is achievable
        int k = K;        // Remaining threshold to adjust scores
        for (int i = 0; isOK && i < N; i++) {
            // If the current score exceeds mid, calculate how much we need to reduce
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            // If we exceed the allowed threshold, mark isOK as false
            if (k < 0) {
                isOK = false;
            }
        }

        // Adjust binary search boundaries based on whether mid is achievable
        if (isOK) {
            ok = mid; // If achievable, move the upper boundary
        } else {
            ng = mid; // If not achievable, move the lower boundary
        }
    }

    // Print the maximum achievable score
    printf("%d\n", ok);

    // Free allocated memory
    free(As);
    free(Fs);
    free(scores);

    return 0;
}

// <END-OF-CODE>
