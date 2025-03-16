#include <stdio.h>

#define MOD 1000000007

int main() {
    // Initialize variables
    int t;
    scanf("%d", &t); // Read the number of test cases

    while (t-- > 0) {
        long n, a, b;
        scanf("%ld %ld %ld", &n, &a, &b); // Read input values for each test case

        // Check if n is less than a, if so, output "No"
        if (n < a) {
            printf("No\n");
            continue;
        }

        // If a equals b, check if n is a multiple of a
        if (a == b) {
            if (n % a == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            continue;
        }

        // Calculate the maximum number of a's that can fit into b
        long x = b / (b - a);

        // If n is greater than x * a, output "Yes"
        if (n > x * a) {
            printf("Yes\n");
            continue;
        }

        // Binary search to find the largest mid such that mid * a < n
        long low = 1;
        long high = x + 1;
        long ans = 1;

        while (low <= high) {
            long mid = (low + high) / 2;

            // Adjust the search range based on the condition
            if (mid * a < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        // Check the final conditions to determine output
        if (n > (ans - 1) * b && n < ans * a) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
