#include <stdio.h> // Including standard input-output library

int main() {
    // Declaring variables to hold input values and a counter
    long long pandu, vundu, urdu, c = 0;
    
    // Reading three long integer values from user input
    scanf("%lld", &pandu); // The first input value
    scanf("%lld", &vundu); // The second input value
    scanf("%lld", &urdu);  // The third input value
    
    // Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
    for (long long i = 1; i <= urdu; i++) {
        c += i * pandu; // Incrementing 'c' by the product of 'i' and 'pandu'
    }
    
    // Checking if the calculated sum 'c' is less than 'vundu'
    if (c < vundu) {
        printf("0"); // If true, print "0"
    } else {
        // If 'c' is greater than or equal to 'vundu', print the difference
        printf("%lld", c - vundu);
    }
    
    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
