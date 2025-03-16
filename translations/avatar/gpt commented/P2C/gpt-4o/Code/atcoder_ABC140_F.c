#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to read a single integer from standard input
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from standard input
void LI(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    // Read the number of elements
    int N = I();
    
    // Read the list of integers
    int S[MAX_SIZE];
    LI(S, N);
    
    // Sort the list in descending order
    qsort(S, N, sizeof(int), compare);
    
    // Initialize a flag array to track which elements have been used
    bool flag[MAX_SIZE] = {true};
    
    // Initialize the current list with the largest element
    int cur[MAX_SIZE];
    int cur_size = 0;
    cur[cur_size++] = S[0];
    
    // Mark the first element as used
    flag[0] = false;
    
    // Iterate N times to build the current list
    for (int i = 0; i < N; i++) {
        int j = 0;  // Index for the current list
        int jM = cur_size;  // Length of the current list
        
        // Try to find the next largest unused element
        for (int k = 0; k < N; k++) {
            // Check if the current element is unused and smaller than the last added element
            if (flag[k] && S[k] < cur[j]) {
                cur[cur_size++] = S[k];  // Add the element to the current list
                j++;  // Move to the next index in the current list
                flag[k] = false;  // Mark this element as used
                
                // If we have added enough elements, break out of the loop
                if (j == jM) {
                    break;
                }
            }
        }
        
        // If we couldn't find a suitable element, return "No"
        if (j < jM) {
            printf("No\n");
            return 0;
        }
        
        // Sort the current list in descending order for the next iteration
        qsort(cur, cur_size, sizeof(int), compare);
    }
    
    // If we successfully built the list, return "Yes"
    printf("Yes\n");
    return 0;
}

// <END-OF-CODE>
