#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int I() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a list of integers from standard input
int* LI() {
    int n = 0;
    int* arr = (int*)malloc(n * sizeof(int));
    int x;
    while (scanf("%d", &x) != EOF) {
        arr = (int*)realloc(arr, (n + 1) * sizeof(int));
        arr[n++] = x;
    }
    return arr;
}

// Function to compare two integers for qsort in descending order
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Main function
int main() {
    // Read the number of elements N
    int N = I();
    
    // Read the list of integers S, sort them in descending order
    int* S = LI();
    qsort(S, N, sizeof(int), compare);
    
    // Initialize a flag array to keep track of used elements
    int* flag = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        flag[i] = 1;
    }
    
    // Initialize the current list with the first element of S
    int* cur = (int*)malloc(sizeof(int));
    cur[0] = S[0];
    
    // Set the flag for the first element to 0
    flag[0] = 0;
    
    // Loop through N times
    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = 1; // cur always has at least one element
        
        // Iterate over the elements of S
        for (int k = 0; k < N; k++) {
            if (flag[k] && S[k] < cur[j]) {
                // Add the element to cur, set its flag to 0, and increment j
                cur = (int*)realloc(cur, (jM + 1) * sizeof(int));
                cur[jM++] = S[k];
                flag[k] = 0;
                if (j == jM - 1) {
                    break;
                }
            }
        }
        
        // If no such element is found, return "No"
        if (j == jM) {
            printf("No\n");
            free(S);
            free(flag);
            free(cur);
            return 0;
        }
        
        // Sort cur in descending order
        qsort(cur, jM, sizeof(int), compare);
    }
    
    // Return "Yes" if the condition is satisfied
    printf("Yes\n");
    
    // Free allocated memory
    free(S);
    free(flag);
    free(cur);
    
    return 0;
}
