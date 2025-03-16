#include <stdio.h>

int main() {
    // Creating a variable to read input from the user
    int n;
    
    // Reading an integer input from the user
    scanf("%d", &n);
    
    // Initializing a counter to count the number of '1's in the binary representation
    int ans = 0;
    
    // Converting the integer n to its binary representation and counting '1's
    while (n > 0) {
        // Checking if the least significant bit is '1'
        if (n % 2 == 1) {
            ans++; // Incrementing the count of '1's
        }
        n /= 2; // Dividing n by 2 to process the next bit
    }
    
    // Printing the total count of '1's in the binary representation
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
