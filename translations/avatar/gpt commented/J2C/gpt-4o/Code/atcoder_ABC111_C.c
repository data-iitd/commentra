#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100010

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    // Create an array to store the input values
    int v[MAX_SIZE];
    
    // Read the number of elements
    int n;
    scanf("%d", &n);
    
    // Read n integers from input and store them in the array v
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    // Initialize arrays to count occurrences of values at different positions
    int vo[MAX_SIZE] = {0}; // Odd indexed counts
    int ve[MAX_SIZE] = {0}; // Even indexed counts
    int vt[MAX_SIZE] = {0}; // Total counts
    
    // Count occurrences of each number in odd and even indexed positions
    for (int i = 0; i < n; i++) {
        vt[v[i]]++; // Increment total count for the value
        if (i % 2 == 0) {
            ve[v[i]]++; // Increment even indexed count
        } else {
            vo[v[i]]++; // Increment odd indexed count
        }
    }
    
    // Sort the count arrays in descending order
    qsort(vo, MAX_SIZE, sizeof(int), compare);
    qsort(ve, MAX_SIZE, sizeof(int), compare);
    qsort(vt, MAX_SIZE, sizeof(int), compare);
    
    // Initialize the answer variable
    int ans = 0;
    
    // Determine the answer based on the counts of the most frequent elements
    if (vo[0] + ve[0] == vt[0]) {
        // If the most frequent odd and even counts sum to the total count
        ans = n - vo[0] - ve[1];
        if (ve[1] == 0) ans = n - vo[1]; // Handle case where ve[1] is zero
    } else {
        // Otherwise, calculate the answer based on the most frequent counts
        ans = n - vo[0] - ve[0];
    }
    
    // Output the final answer
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
