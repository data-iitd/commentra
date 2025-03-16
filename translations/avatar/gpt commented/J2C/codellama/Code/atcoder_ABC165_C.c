#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

// Declare arrays to hold input values and variables for dimensions and result
int *a = NULL; 
int *b = NULL; 
int *c = NULL; 
int *d = NULL; 
int n = 0; 
int m = 0; 
int q = 0; 
long ans = -100L; // Initialize answer to a very low value

void dfs(int *list, int size) { 
    // Check if the current list has reached the required size (n)
    if (size == n) { 
        long score = 0L; // Initialize score for the current configuration
        
        // Calculate the score based on the queries
        for (int i = 0; i < q; ++i) { 
            // If the condition is met, add the corresponding value to the score
            score += (list[b[i]] - list[a[i]] == c[i]) ? d[i] : 0L; 
        } 
        
        // Update the maximum score if the current score is higher
        ans = (ans > score) ? ans : score; 
        return; 
    } 
    
    // If the list is not empty, continue adding numbers from the last added number to m
    if (size > 0) { 
        for (int num = list[size - 1]; num <= m; ++num) { 
            list[size] = num; // Add the current number to the list
            dfs(list, size + 1); // Recur with the updated list
        } 
    } else { 
        // If the list is empty, start adding numbers from 1 to m
        for (int num = 1; num <= m; ++num) { 
            list[size] = num; // Add the current number to the list
            dfs(list, size + 1); // Recur with the updated list
        } 
    } 
} 

int main() { 
    // Create a Scanner object for input
    int n, m, q; 
    scanf("%d %d %d", &n, &m, &q); 
    
    // Initialize arrays based on the number of queries (q)
    a = (int *)malloc(q * sizeof(int)); 
    b = (int *)malloc(q * sizeof(int)); 
    c = (int *)malloc(q * sizeof(int)); 
    d = (int *)malloc(q * sizeof(int)); 
    
    // Read the query parameters into the arrays
    for (int i = 0; i < q; ++i) { 
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]); 
        a[i]--; // Store a[i] (0-indexed)
        b[i]--; // Store b[i] (0-indexed)
    } 
    
    // Start the depth-first search (DFS) to find the maximum score
    int *list = (int *)malloc((n + 1) * sizeof(int)); 
    dfs(list, 0); 
    
    // Output the maximum score found
    printf("%ld\n", ans); 
    return 0; 
} 

