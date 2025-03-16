#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000

// Function to read an integer from standard input
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from standard input
void LI(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    // Read the number of elements N
    int N = I();
    
    // Read the list of integers S
    int S[MAX_N];
    LI(S, N);
    
    // Sort S in descending order
    qsort(S, N, sizeof(int), compare);
    
    // Initialize a flag array to keep track of used elements
    bool flag[MAX_N] = {true};
    
    // Initialize the current list with the first element of S
    int cur[MAX_N];
    int cur_size = 1;
    cur[0] = S[0];
    flag[0] = false;
    
    // Loop through N times
    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = cur_size;
        
        // Iterate over the elements of S
        for (int k = 0; k < N; k++) {
            if (flag[k] && S[k] < cur[j]) {
                // Add the element to cur, set its flag to false, and increment j
                cur[cur_size] = S[k];
                cur_size++;
                j++;
                flag[k] = false;
                if (j == jM) {
                    break;
                }
            }
        }
        
        // If no such element is found, return "No"
        if (j < jM) {
            printf("No\n");
            return 0;
        }
        
        // Sort cur in descending order
        qsort(cur, cur_size, sizeof(int), compare);
    }
    
    // Return "Yes" if the condition is satisfied
    printf("Yes\n");
    return 0;
}

// <END-OF-CODE>
