
#include<stdio.h>
#include<stdlib.h>

// Function to check if it is possible to distribute weights
int check(int n, int wei, int *book, int size) {
    int tmp = wei; // Temporary variable to hold the remaining weight
    n--; // Decrease the number of available books by one
    for(int i = 0; i < size; i++) {
        // If the current weight exceeds the available weight
        if(tmp < book[i]) {
            // If there are still books left to use
            if(n > 0) {
                n--; // Use one book
                tmp = wei; // Reset the temporary weight to the original weight
                // Check again if the current weight exceeds the available weight
                if(tmp < book[i])
                    return 0; // Not possible to distribute
            } else {
                return 0; // No books left to use
            }
        }
        // Deduct the current book's weight from the temporary weight
        tmp -= book[i];
    }
    return 1; // Successfully distributed the weights
}

int main() {
    int m, n; // m: maximum weight, n: number of books
    // Read input until m is zero
    while(scanf("%d %d", &m, &n), m) {
        int *book = (int *)malloc(sizeof(int) * n); // Array to store the weights of the books
        // Read the weights of the books
        for(int i = 0; i < n; i++) {
            scanf("%d", &book[i]); // Read each book's weight
        }

        /*
        // Uncomment this block to check for multiple weight distributions
        while(true) {
            int tmp;
            scanf("%d", &tmp); // Read weight to check
            if(check(m, tmp, book, n))
                printf("YES\n"); // Possible distribution
            else
                printf("NO\n"); // Not possible distribution
        }
        */

        int l = 0; // Lower bound for binary search
        int r = 1500000; // Upper bound for binary search
        int ans; // Variable to store the answer
        // Perform binary search to find the maximum weight that can be distributed
        while(l < r) {
            // Check if the middle weight can be distributed
            if(check(m, (l + r) / 2, book, n)) {
                ans = (l + r) / 2; // Update answer
                // If the upper bound equals the middle, break the loop
                if(r == (l + r) / 2)
                    break;
                r = (l + r) / 2; // Move the upper bound down
            } else {
                // If the lower bound equals the middle, break the loop
                if(l == (l + r) / 2)
                    break;
                l = (l + r) / 2; // Move the lower bound up
            }
        }
        printf("%d\n", ans); // Output the maximum weight that can be distributed

        free(book); // Free the memory allocated for the book array
    }
}

