#include <stdio.h>
#include <math.h>

#define REP(i,n) for(int i=0; i<n; ++i) // For loop for iterating from 0 to n-1

int main() {
    int n; // Number of test cases
    scanf("%d", &n); // Read the number of test cases from standard input

    while (n--) { // Process each test case
        int p, q; // Read p and q from standard input
        scanf("%d %d", &p, &q);

        int l = (int)sqrt(p*p + q*q); // Calculate the square root of p^2 + q^2

        int isprime = 1; // Initialize isprime to true

        REP(i, l) REP(j, l) { // Iterate through all possible integers x from 0 to l^2
            int x = i*i + j*j; // Calculate x = i^2 + j^2

            if (x <= 1) continue; // If x is less than or equal to 1, skip to the next iteration
            if (x > p*p + q*q) continue; // If x is greater than p^2 + q^2, skip to the next iteration

            if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) { // Check if p*i + q*j and q*i - p*j are both divisible by x
                isprime = 0; // If so, set isprime to false
                break; // Exit the inner loop
            }
        }

        printf("%s\n", isprime ? "P" : "C"); // Print "P" if isprime is still true, otherwise print "C"
    }

    return 0;
}

// <END-OF-CODE>
