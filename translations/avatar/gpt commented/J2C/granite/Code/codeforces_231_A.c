
#include <stdio.h> // Including the standard input/output library

int main() {
    int t, a, b, c, count = 0; // Declaring variables for the number of test cases, integers, and the count of valid cases
    
    // Reading the number of test cases
    scanf("%d", &t);
    
    // Looping through each test case
    while (t-- > 0) {
        // Reading the three integers
        scanf("%d %d %d", &a, &b, &c);
        
        // Checking if at least one of the integers is equal to 1
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Incrementing the count if the condition is met
        }
    }
    
    // Outputting the total count of valid cases
    printf("%d\n", count);
    
    return 0; // Returning 0 to indicate successful execution
}
