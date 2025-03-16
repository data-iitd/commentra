
#include <stdio.h> // Include the standard input/output library

int main() {
    // Declare variables to hold input values and a counter
    long pandu, vundu, urdu, c = 0;
    
    // Read three long integer values from user input
    scanf("%ld %ld %ld", &pandu, &vundu, &urdu); // The first input value
    
    // Calculate the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
    for (int i = 1; i <= urdu; i++) {
        c += i * pandu; // Increment 'c' by the product of 'i' and 'pandu'
    }
    
    // Check if the calculated sum 'c' is less than 'vundu'
    if (c < vundu) {
        printf("0"); // If true, print "0"
    } else {
        // If 'c' is greater than or equal to 'vundu', print the difference
        printf("%ld", c - vundu);
    }
    
    return 0; // Return 0 to indicate successful execution
}
