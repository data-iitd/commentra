
#include <stdio.h>
#include <math.h>

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);
    
    // Process each test case
    while (n--){
        int p, q;
        // Read the values of p and q
        scanf("%d %d", &p, &q);

        // Calculate the length l based on the Euclidean distance from the origin
        int l = sqrt(p*p + q*q);
        
        // Initialize a flag to check if the current case is prime
        int isprime = 1;

        // Check all combinations of i and j within the range [0, l)
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                // Calculate the sum of squares of i and j
                int x = i*i + j*j;

                // Skip values of x that are not in the valid range
                if (x <= 1 || x >= p*p + q*q) continue;

                // Check the conditions for primality based on the given formula
                if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) 
                    isprime = 0; // Set isprime to false if conditions are met
            }
        }

        // Output "P" if prime, otherwise output "C"
        printf("%c\n", isprime? 'P' : 'C');
    }

    return 0; // End of the program
}
