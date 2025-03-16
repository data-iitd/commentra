#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

<<<<<<< HEAD
// Function to compare two integers for qsort
=======
>>>>>>> 98c87cb78a (data updated)
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // For descending order
}

<<<<<<< HEAD
// Function to read an integer from stdin
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read an array of integers from stdin
void readInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = readInt();
    }
}

int main() {
    // Read the number of elements N and the maximum number of operations K
    int N = readInt();
    int K = readInt();
    
    // Allocate memory for the lists of integers
    int *As = (int *)malloc(N * sizeof(int));
    int *Fs = (int *)malloc(N * sizeof(int));
    
    // Read the list of integers As
    readInts(As, N);
    
    // Read the list of integers Fs
    readInts(Fs, N);
=======
int main() {
    // Read the number of elements N and the maximum number of operations K
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Read the list of integers As
    int *As = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &As[i]);
    }
    
    // Read the list of integers Fs
    int *Fs = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &Fs[i]);
    }
>>>>>>> 98c87cb78a (data updated)
    
    // Sort As in ascending order
    qsort(As, N, sizeof(int), compare);
    
    // Sort Fs in descending order
    qsort(Fs, N, sizeof(int), compare);
    
    // Create a list to store the scores
    int *scores = (int *)malloc(N * sizeof(int));
    
    // Calculate the scores by multiplying corresponding elements of As and Fs
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }
    
    // Sort the scores in descending order
    qsort(scores, N, sizeof(int), compare);
    
    // Initialize the boundaries for binary search
    int ok = scores[0];
    int ng = -1;
    
    // Perform binary search to find the maximum score
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        
        // Check if it's possible to achieve mid score with at most K operations
        bool isOK = true;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = false;
            }
        }
        
        // Adjust the search boundaries based on the result of the check
        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    
    // Print the maximum score found
    printf("%d\n", ok);
    
    // Free allocated memory
    free(As);
    free(Fs);
    free(scores);
    
    return 0;
}

// <END-OF-CODE>
