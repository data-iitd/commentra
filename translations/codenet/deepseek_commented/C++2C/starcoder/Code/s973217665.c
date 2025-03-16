#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of test cases
    while (n--){
        int p, q;
        scanf("%d %d", &p, &q); // Read the values of p and q for each test case
        int l = (int)sqrt(p*p + q*q); // Calculate the length of the hypotenuse
        int isprime = 1; // Initialize a flag to check if the number is prime
        for (int i = 0; i < l; i++) { // Loop through all pairs (i, j) within the range of l
            for (int j = 0; j < l; j++) {
                int x = i*i + j*j; // Calculate the sum of squares
                if (x <= 1 || x >= p*p + q*q) continue; // Skip if x is out of range
                if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) isprime = 0; // Check the conditions
            }
        }
        printf("%s\n", isprime? "P" : "C"); // Print the result
    }

    return 0;
}

