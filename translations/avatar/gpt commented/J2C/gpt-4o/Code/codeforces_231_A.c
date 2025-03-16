#include <stdio.h> // Including standard input-output library

int main() {
    int t; // Variable to store the number of test cases
    scanf("%d", &t); // Reading the number of test cases
    int count = 0; // Initializing a counter to keep track of valid cases
    
    // Looping through each test case
    while (t-- > 0) {
        int a, b, c; // Variables to store the three integers
        scanf("%d %d %d", &a, &b, &c); // Reading the three integers
        
        // Checking if at least one of the integers is equal to 1
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Incrementing the count if the condition is met
        }
    }
    
    // Outputting the total count of valid cases
    printf("%d\n", count);
    
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
