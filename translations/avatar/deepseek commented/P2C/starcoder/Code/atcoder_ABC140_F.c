
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from standard input
int* LI() {
    int *x = (int*)malloc(sizeof(int) * 100);
    int i = 0;
    while (scanf("%d", &x[i])!= EOF) {
        i++;
    }
    return x;
}

int main() {
    // Read the number of elements N
    int N = I();
    
    // Read the list of integers S, sort them in descending order
    int* S = LI();
    qsort(S, N, sizeof(int), (int (*)(const void *, const void *))qsort_cmp);
    
    // Initialize a flag array to keep track of used elements
    int* flag = (int*)malloc(sizeof(int) * N);
    memset(flag, 1, sizeof(int) * N);
    
    // Initialize the current list with the first element of S
    int* cur = (int*)malloc(sizeof(int) * 100);
    cur[0] = S[0];
    
    // Set the flag for the first element to False
    flag[0] = 0;
    
    // Loop through N times
    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = 1;
        
        // Iterate over the elements of S
        for (int k = 0; k < N; k++) {
            if (flag[k] && S[k] < cur[j]) {
                // Add the element to cur, set its flag to False, and increment j
                cur[jM] = S[k];
                jM++;
                flag[k] = 0;
                if (j == jM - 1) {
                    break;
                }
            }
        }
        
        // If no such element is found, return "No"
        if (j == jM - 1) {
            return "No";
        }
        
        // Sort cur in descending order
        qsort(cur, jM, sizeof(int), (int (*)(const void *, const void *))qsort_cmp);
    }
    
    // Return "Yes" if the condition is satisfied
    return "Yes";
}

// Function to compare two integers
int qsort_cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

