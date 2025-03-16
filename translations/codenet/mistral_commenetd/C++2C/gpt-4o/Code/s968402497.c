#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library for general functions

#define mod 1000000007 // Modulus constant
#define mod9 998244353 // Modulus constant
#define INF 0x3f3f3f3f // Maximum integer constant

int main() {
    int tc, n, m, fl = 0; // Declare variables

    // Read input
    scanf("%d%d%d", &tc, &n, &m);
    
    // Check if 'n' is greater than 'm' and swap them if necessary
    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }
    
    // Iterate through each possible value of 'i' from 1 to 'm'
    for (int i = 1; i <= m; i++) {
        // Check if 'i' multiplied by 'tc' is within the range of 'n' to 'm'
        if (i * tc >= n && i * tc <= m) {
            // If so, print "OK" and set the flag 'fl' to 1
            printf("OK\n");
            fl = 1;
            // Break out of the loop since we have found the answer
            break;
        }
    }
    
    // If the flag 'fl' is still 0, print "NG"
    if (fl == 0) {
        puts("NG");
    }
    
    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
