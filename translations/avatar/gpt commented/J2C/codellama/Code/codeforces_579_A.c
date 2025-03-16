#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a Scanner object to read input from the user
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    
    // Initializing an empty string to store the binary representation
    char s[100] = "";
    
    // Converting the integer n to its binary representation
    while (n > 0) {
        int x = n % 2; // Getting the least significant bit (0 or 1)
        n /= 2; // Dividing n by 2 to process the next bit
        strcat(s, x + '0'); // Appending the bit to the binary string
    }
    
    // Initializing a counter to count the number of '1's in the binary representation
    int ans = 0;
    
    // Iterating through the binary string to count '1's
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '1') { // Checking if the current character is '1'
            ans++; // Incrementing the count of '1's
        }
    }
    
    // Printing the total count of '1's in the binary representation
    printf("The number of '1's in the binary representation of %d is %d\n", n, ans);
    
    return 0;
}

