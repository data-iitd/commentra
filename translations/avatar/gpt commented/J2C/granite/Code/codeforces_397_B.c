
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
    // Define constants for the problem
    #define N 100000
    #define MOD 100000007

    // Initialize variables and data structures
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, a, b;
        scanf("%lld %lld %lld", &n, &a, &b);

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
        long long x = b / (b - a);

        // If n is greater than x * a, output "Yes"
        if (n > x * a) {
            printf("Yes\n");
            continue;
        }

        // Binary search to find the largest mid such that mid * a < n
        long long low = 1, high = x + 1, ans = 1;
        while (low <= high) {
            long long mid = (low + high) / 2;
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
