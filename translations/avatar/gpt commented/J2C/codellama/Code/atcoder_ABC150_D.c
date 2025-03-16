#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int n, m, i; 
    scanf("%d %d", &n, &m); 
    
    // Read the first integer n, which represents the number of elements
    // Read the second integer m, which represents the upper limit
    
    // Initialize an array to hold the processed values
    int a[n]; 
    
    // Read n integers from input, divide each by 2, and store in array a
    for (i = 0; i < n; i++) { 
        scanf("%d", &a[i]); 
        a[i] = a[i] / 2; 
    } 
    
    long gcd; 
    long lcd = 1; // Initialize the least common denominator (lcd) to 1
    
    // Calculate the least common multiple (lcd) of the array elements
    for (i = 0; i < n; i++) { 
        gcd = getGCD(lcd, a[i]); // Get the greatest common divisor (gcd) of lcd and current element
        lcd = lcd * a[i] / gcd; // Update lcd using the formula: lcd = (lcd * a[i]) / gcd
        
        // If lcd exceeds m, print 0 and exit
        if (lcd > m) { 
            printf("0"); 
            return 0; 
        } 
    } 
    
    // Check if the condition for each element in the array is satisfied
    for (i = 0; i < n; i++) { 
        // If lcd divided by the current element is even, print 0 and exit
        if ((lcd / a[i]) % 2 == 0) { 
            printf("0"); 
            return 0; 
        } 
    } 
    
    // Calculate and print the final result based on the value of m and lcd
    printf("%ld", (m / lcd + 1) / 2); 
    return 0; 
} 

// Method to compute the greatest common divisor (gcd) using recursion
long getGCD(long a, long b) { 
    if (b == 0) { 
        return a; 
    } else { 
        return getGCD(b, a % b); // Recursive call to find gcd
    } 
} 

