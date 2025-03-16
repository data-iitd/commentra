#include <stdio.h>  // Include the standard input/output library

int main() {
    int n, k;
    long long int l = 0, r = 0;  // Declare integer variables for counting

    scanf("%d%d", &n, &k);  // Read input values for n and k

    if (k % 2 == 0) {  // Check if k is even
        for (int i = 1; i <= n; i++) {  // Iterate from 1 to n
            if (i % k == k / 2)  // Check if i modulo k equals k/2
                l++;  // Increment l if condition is true
            else if (i % k == 0)  // Check if i modulo k equals 0
                r++;  // Increment r if condition is true
        }
        printf("%lld\n", l * l * l + r * r * r);  // Print the result of l^3 + r^3
    } else {  // If k is odd
        for (int i = 1; i <= n; i++) {  // Iterate from 1 to n
            if (i % k == 0)  // Check if i modulo k equals 0
                r++;  // Increment r if condition is true
        }
        printf("%lld\n", r * r * r);  // Print the result of r^3
    }

    return 0;  // End of the main function
}

