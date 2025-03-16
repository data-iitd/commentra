
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

int N, K;
int A[100000];
int F[100000];
int S[100000];

int main() {
    // Read the number of elements N and the threshold K
    scanf("%d %d", &N, &K);
    
    // Read the two slices of integers As and Fs
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &F[i]);
    }

    // Sort the As slice in ascending order
    qsort(A, N, sizeof(int), cmpfunc);
    // Sort the Fs slice in descending order
    qsort(F, N, sizeof(int), cmpfunc2);
    
    // Create a slice to hold the scores calculated from As and Fs
    for (int i = 0; i < N; i++) {
        S[i] = A[i] * F[i];
    }
    
    // Sort the scores in descending order
    qsort(S, N, sizeof(int), cmpfunc);

    // Initialize binary search boundaries
    int ok = S[0]; // The maximum possible score
    int ng = -1;    // The minimum possible score

    // Perform binary search to find the maximum score that can be achieved
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2; // Calculate the midpoint of the current range

        bool isOK = true; // Flag to check if the current mid is achievable
        int k = K;       // Remaining threshold to adjust scores
        for (int i = 0; isOK && i < N; i++) {
            // If the current score exceeds mid, calculate how much we need to reduce
            if (S[i] > mid) {
                k -= A[i] - mid / F[i];
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

    return 0;
}

// Compare function for qsort to sort integers in ascending order
int cmpfunc(const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

// Compare function for qsort to sort integers in descending order
int cmpfunc2(const void * a, const void * b) {
   return (*(int*)b - *(int*)a);
}

// Read the next integer from input and return it
int ReadInt() {
    int v;
    scanf("%d", &v);
    return v;
}

// Read the next token from input as a string
char Read() {
    char c;
    scanf("%c", &c);
    return c;
}

// Read N integers from input and return them as a slice
int* ReadInts(int N) {
    int* ret = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        ret[i] = ReadInt();
    }
    return ret;
}

// Initialize a scanner for reading input
void init() {
    // No need to initialize the scanner in C
}

// Translate the above C code to Python and end with comment "