#include <stdio.h>
#include <math.h>
<<<<<<< HEAD
=======
#include <stdbool.h>
>>>>>>> 98c87cb78a (data updated)

// Macros for loop iterations
#define REP(i,n) for(int i=0; i<n; ++i)

// Type definitions for convenience
typedef long long ll;

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);
    
    // Process each test case
    while (n--) {
        int p, q;
        // Read the values of p and q
        scanf("%d %d", &p, &q);

        // Calculate the length l based on the Euclidean distance from the origin
        int l = (int)sqrt(p*p + q*q);
        
        // Initialize a flag to check if the current case is prime
<<<<<<< HEAD
        int isprime = 1;
=======
        bool isprime = true;
>>>>>>> 98c87cb78a (data updated)

        // Check all combinations of i and j within the range [0, l)
        REP(i, l) REP(j, l) {
            // Calculate the sum of squares of i and j
            int x = i*i + j*j;

            // Skip values of x that are not in the valid range
            if (x <= 1 || x >= p*p + q*q) continue;

            // Check the conditions for primality based on the given formula
            if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) 
<<<<<<< HEAD
                isprime = 0; // Set isprime to false if conditions are met
=======
                isprime = false; // Set isprime to false if conditions are met
>>>>>>> 98c87cb78a (data updated)
        }

        // Output "P" if prime, otherwise output "C"
        printf("%s\n", isprime ? "P" : "C");
    }

    return 0; // End of the program
}

// <END-OF-CODE>
