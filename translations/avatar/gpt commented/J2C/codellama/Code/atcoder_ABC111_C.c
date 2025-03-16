#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the user
    int n; 
    scanf("%d", &n); 
    
    // Read the number of elements
    int v[100010]; 
    
    // Read n integers from input and store them in the array v
    for (int i = 0; i < n; i++) { 
        scanf("%d", &v[i]); 
    } 
    
    // Initialize arrays to count occurrences of values at different positions
    int vo[100010]; // Odd indexed counts
    int ve[100010]; // Even indexed counts
    int vt[100010]; // Total counts
    
    // Fill the count arrays with zeros
    memset(vo, 0, sizeof(vo)); 
    memset(ve, 0, sizeof(ve)); 
    memset(vt, 0, sizeof(vt)); 
    
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
    qsort(vo, 100010, sizeof(int), compare); 
    qsort(ve, 100010, sizeof(int), compare); 
    qsort(vt, 100010, sizeof(int), compare); 
    
    // Initialize the answer variable
    int ans = 0; 
    
    // Determine the answer based on the counts of the most frequent elements
    if (vo[0] + ve[0] == vt[0]) { 
        // If the most frequent odd and even counts sum to the total count
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]); 
    } else { 
        // Otherwise, calculate the answer based on the most frequent counts
        ans = n - vo[0] - ve[0]; 
    } 
    
    // Output the final answer
    printf("%d\n", ans); 
    
    // Close the scanner to prevent resource leaks
    return 0; 
} 

int compare(const void *a, const void *b) { 
    return *(int*)b - *(int*)a; 
} 

int min(int a, int b) { 
    return a < b ? a : b; 
} 

