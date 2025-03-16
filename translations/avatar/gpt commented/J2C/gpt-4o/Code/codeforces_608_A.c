#include <stdio.h>

int main() {
    // Initialize variables for number of pairs (n) and minimum score (s)
    int n, s;
    // Read the number of pairs and the minimum score
    scanf("%d %d", &n, &s);
    
    // Initialize a variable to keep track of the maximum sum of pairs
    int max = 0;
    
    // Loop through each pair of integers
    while (n-- > 0) {
        // Read the two integers f and t
        int f, t;
        scanf("%d %d", &f, &t);
        // Update max if the sum of f and t is greater than the current max
        if (max < f + t) {
            max = f + t;
        }
    }
    
    // Print the maximum value between max and s
    printf("%d\n", (max > s) ? max : s);
    
    return 0;
}

// <END-OF-CODE>
