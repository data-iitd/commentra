#include <stdio.h>

#define INF 1000000000

// Global variable to control debug output
int debug = 0;

int main() {
    // Declare variables for input
    int n, k, x, y;
    
    // Read input values: n (total items), k (threshold), x (cost for first k items), y (cost for items beyond k)
    scanf("%d %d %d %d", &n, &k, &x, &y);
    
    // Initialize sum to accumulate total cost
    int sum = 0;

    // Loop through each item from 1 to n
    for (int i = 1; i <= n; i++) {
        // If the current item index exceeds k, add cost y; otherwise, add cost x
        if (i > k) 
            sum += y; // Cost for items beyond the threshold
        else 
            sum += x; // Cost for items within the threshold
    }

    // Output the total calculated cost
    printf("%d\n", sum);

    return 0; // End of the program
}

// <END-OF-CODE>
