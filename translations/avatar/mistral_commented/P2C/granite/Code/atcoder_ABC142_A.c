
#include <stdio.h>

int main() {
    // Read an integer n from the user
    int n;
    scanf("%d", &n);
    // Initialize a variable t to zero
    int t = 0;
    // Iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Check if the index i is odd
        if (i + 1 & 1) {
            // If it is odd, increment the variable t by 1
            t++;
        }
    }
    // Print the result t/n as the output
    printf("%f\n", (float)t / n);
    return 0;
}
// END-OF-CODE