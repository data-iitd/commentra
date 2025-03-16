#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaring variables to hold input values and a counter
    long pandu, vundu, urdu, c = 0;
    
    // Reading three long integer values from user input
    scanf("%ld %ld %ld", &pandu, &vundu, &urdu);
    
    // Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
    for (int i = 1; i <= urdu; i++) {
        c += i * pandu; // Incrementing 'c' by the product of 'i' and 'pandu'
    }
    
    // Checking if the calculated sum 'c' is less than 'vundu'
    if (c < vundu) {
        printf("0"); // If true, print "0"
    } else {
        // If 'c' is greater than or equal to 'vundu', print the difference
        printf("%ld", c - vundu);
    }
    
    return 0;
}

