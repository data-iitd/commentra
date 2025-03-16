#include <stdio.h>
#include <stdlib.h>

#define MAX_Q 100 // Assuming a maximum size for queries

// Declare arrays to hold input values and variables for dimensions and result
int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];
int n = 0, m = 0, q = 0;
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
        if (score > ans) {
            ans = score;
        }
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
    // Create a buffer for the list
    int *list = (int *)malloc(n * sizeof(int));
    
    // Read the values of n, m, and q from input
    scanf("%d %d %d", &n, &m, &q);
    
    // Read the query parameters into the arrays
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i]--; // Convert to 0-indexed
        b[i]--; // Convert to 0-indexed
    }
    
    // Start the depth-first search (DFS) to find the maximum score
    dfs(list, 0);
    
    // Output the maximum score found
    printf("%ld\n", ans);
    
    // Free the allocated memory
    free(list);
    
    return 0;
}

// <END-OF-CODE>
