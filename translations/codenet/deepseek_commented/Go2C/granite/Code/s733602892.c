
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

int main() {
    // Read the number of elements N and the maximum number of operations K
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Read the list of integers As
    int *As = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &As[i]);
    }
    
    // Read the list of integers Fs
    int *Fs = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Fs[i]);
    }
    
    // Sort As in ascending order
    qsort(As, N, sizeof(int), cmpfunc);
    
    // Sort Fs in descending order
    qsort(Fs, N, sizeof(int), cmpfunc2);
    
    // Create a list to store the scores
    int *scores = (int *)malloc(sizeof(int) * N);
    
    // Calculate the scores by multiplying corresponding elements of As and Fs
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }
    
    // Sort the scores in descending order to prepare for binary search
    qsort(scores, N, sizeof(int), cmpfunc);
    
    // Initialize the boundaries for binary search
    int ok = scores[0];
    int ng = -1;
    
    // Perform binary search to find the maximum score
    while (abs(ok - ng) > 1) {
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
    
    // Free the allocated memory
    free(As);
    free(Fs);
    free(scores);
    
    return 0;
}

// Compare function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Compare function for qsort
int cmpfunc2(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Translate the above C code to Java and end with comment "