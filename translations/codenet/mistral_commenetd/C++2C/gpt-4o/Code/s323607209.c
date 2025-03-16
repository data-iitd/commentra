#include <stdio.h>
// Include the standard input output header file

int main() {
    int n, k; // Declare two integer variables n and k
    long long int l = 0, r = 0; // Initialize l and r to zero

    scanf("%d%d", &n, &k); // Read two integers n and k from the standard input using the scanf function

    if (k % 2 == 0) { // Check if k is even
        for (int i = 1; i <= n; i++) { // Iterate through the numbers from 1 to n
            if (i % k == k / 2) { // Check if the remainder of i divided by k is equal to k/2
                l++; // If it is, increment the variable l by 1
            } else if (i % k == 0) { // Else if the remainder of i divided by k is equal to 0
                r++; // Increment the variable r by 1
            }
        }
        printf("%lld\n", l * l * l + r * r * r); // Calculate and print the result using the expressions l*l*l+r*r*r
    } else { // Else if k is odd
        for (int i = 1; i <= n; i++) { // Iterate through the numbers from 1 to n
            if (i % k == 0) { // Check if the remainder of i divided by k is equal to 0
                r++; // If it is, increment the variable r by 1
            }
        }
        printf("%lld\n", r * r * r); // Calculate and print the result using the expression r*r*r
    }

    return 0; // Return 0 to indicate successful completion
}
// <END-OF-CODE>
