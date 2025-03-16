#include <stdio.h>

int main() {
    // Create variables to read input
    int n, k;
    
    // Read the number of elements (n) and a threshold value (k)
    scanf("%d %d", &n, &k);
    
    // Initialize variables to keep track of the last number and its consecutive occurrences
    int l = 0, c = 1;
    
    // Loop to read n numbers and count consecutive occurrences
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a == l) {
            c += 1; // Increment count if the current number is the same as the last
        } else {
            c = 1; // Reset count if the current number is different
        }
        l = a; // Update the last number
    }
    
    // Check if the number of consecutive occurrences plus the threshold value is greater than n
    if (c + k > n) {
        printf("%d\n", n - c); // Print the number of elements to remove
    } else {
        printf("-1\n"); // Print -1 if it's not possible to satisfy the condition
    }
    
    return 0;
}

// <END-OF-CODE>
