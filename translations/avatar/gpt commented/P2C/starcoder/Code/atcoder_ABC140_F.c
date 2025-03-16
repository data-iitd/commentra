#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single integer from standard input
int I() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a list of integers from standard input
int* LI() {
    int n = I();
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    // Read the number of elements
    int N = I();
    
    // Read the list of integers, sort it in descending order
    int* S = LI();
    qsort(S, N, sizeof(int), (int (*)(const void*, const void*)) qsort_cmp);
    
    // Initialize a flag list to track which elements have been used
    int* flag = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        flag[i] = 1;
    }
    
    // Initialize the current list with the largest element
    int* cur = (int*) malloc(N * sizeof(int));
    cur[0] = S[0];
    
    // Mark the first element as used
    flag[0] = 0;
    
    // Iterate N times to build the current list
    for (int i = 0; i < N; i++) {
        int j = 0;  // Index for the current list
        int jM = 1;  // Length of the current list
        
        // Try to find the next largest unused element
        for (int k = 0; k < N; k++) {
            // Check if the current element is unused and smaller than the last added element
            if (flag[k] && S[k] < cur[j]) {
                cur[jM] = S[k];  // Add the element to the current list
                jM++;  // Move to the next index in the current list
                flag[k] = 0;  // Mark this element as used
                
                // If we have added enough elements, break out of the loop
                if (jM == j) {
                    break;
                }
            }
        } else {
            // If we couldn't find a suitable element, return "No"
            printf("No\n");
            return 0;
        }
        
        // Sort the current list in descending order for the next iteration
        qsort(cur, jM, sizeof(int), (int (*)(const void*, const void*)) qsort_cmp);
    }
    
    // If we successfully built the list, return "Yes"
    printf("Yes\n");
    return 0;
}

// Function to compare two integers
int qsort_cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

