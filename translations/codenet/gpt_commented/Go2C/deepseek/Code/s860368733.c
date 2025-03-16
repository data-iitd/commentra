#include <stdio.h>

int main() {
    // Declare variables for the number of elements (n) and the number of comparisons (m)
    int n, m;
    
    // Read the values of n and m from standard input
    scanf("%d %d", &n, &m);
    
    // Create an array to hold the heights of n elements
    int h[n];
    
    // Read the heights of the n elements from standard input
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    
    // Declare variables for the two elements to compare (a and b)
    int a, b;
    
    // Create an array to keep track of unique elements that are involved in comparisons
    int counter[n];
    for (int i = 0; i < n; i++) {
        counter[i] = 0;
    }
    
    // Loop through m comparisons
    for (int i = 0; i < m; i++) {
        // Read the indices of the two elements to compare
        scanf("%d %d", &a, &b);
        
        // Compare the heights of the two elements
        if (h[a - 1] < h[b - 1]) {
            // If height of a is less than height of b, increment counter for a
            counter[a - 1]++;
        } else if (h[a - 1] > h[b - 1]) {
            // If height of a is greater than height of b, increment counter for b
            counter[b - 1]++;
        } else if (h[a - 1] == h[b - 1]) {
            // If heights are equal, increment counters for both a and b
            counter[a - 1]++;
            counter[b - 1]++;
        }
    }
    
    // Count the number of elements that were not involved in any comparisons
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (counter[i] == 0) {
            count++;
        }
    }
    
    // Print the number of elements that were not involved in any comparisons
    printf("%d\n", count);
    
    return 0;
}
