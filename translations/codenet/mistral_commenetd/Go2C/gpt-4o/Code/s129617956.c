#include <stdio.h>
#include <math.h>

int min(int i, int j) {
    return (i < j) ? i : j;
}

int countDigits(int b) {
    int ndigit = 0;
    while (b > 0) {
        b /= 10;
        ndigit++;
    }
    return ndigit;
}

int main() {
    int n;
    scanf("%d", &n); // Read an integer from standard input

    int rt = (int)sqrt(n); // Calculate the square root of n
    int minf = 100; // Initialize minimum factor with a large value

    // Check divisibility for numbers from 1 to the square root of n
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = countDigits(b);
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }

    // Print the result
    printf("%d\n", minf);
    return 0;
}

/* <END-OF-CODE> */
