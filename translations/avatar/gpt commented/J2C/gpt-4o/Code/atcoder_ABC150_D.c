#include <stdio.h>

long getGCD(long a, long b) {
    if (b == 0) {
        return a;
    } else {
        return getGCD(b, a % b);
    }
}

int main() {
    // Create variables to hold input values
    int n, m;
    
    // Read the first integer n, which represents the number of elements
    scanf("%d", &n);
    
    // Read the second integer m, which represents the upper limit
    scanf("%d", &m);
    
    // Initialize an array to hold the processed values
    int a[n];
    
    // Read n integers from input, divide each by 2, and store in array a
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        a[i] = temp / 2;
    }
    
    long gcd;
    long lcd = 1; // Initialize the least common denominator (lcd) to 1
    
    // Calculate the least common multiple (lcd) of the array elements
    for (int i = 0; i < n; i++) {
        gcd = getGCD(lcd, a[i]); // Get the greatest common divisor (gcd) of lcd and current element
        lcd = lcd * a[i] / gcd; // Update lcd using the formula: lcd = (lcd * a[i]) / gcd
        
        // If lcd exceeds m, print 0 and exit
        if (lcd > m) {
            printf("0\n");
            return 0;
        }
    }
    
    // Check if the condition for each element in the array is satisfied
    for (int i = 0; i < n; i++) {
        // If lcd divided by the current element is even, print 0 and exit
        if ((lcd / a[i]) % 2 == 0) {
            printf("0\n");
            return 0;
        }
    }
    
    // Calculate and print the final result based on the value of m and lcd
    printf("%ld\n", (m / lcd + 1) / 2);
    
    return 0;
}

// <END-OF-CODE>
