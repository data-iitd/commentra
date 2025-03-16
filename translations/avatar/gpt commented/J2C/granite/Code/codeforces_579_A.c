
#include <stdio.h> // Include the necessary header file
#include <stdlib.h> // Include the necessary header file

int main() {
    // Creating a Scanner object to read input from the user
    int n; // Declaring an integer variable n to store the input
    scanf("%d", &n); // Reading an integer input from the user
    
    // Initializing an empty string to store the binary representation
    char s[1000]; // Declaring a character array s to store the binary representation
    int i = 0; // Initializing a counter i to keep track of the index in the binary string
    
    // Converting the integer n to its binary representation
    while (n > 0) {
        int x = n % 2; // Getting the least significant bit (0 or 1)
        n /= 2; // Dividing n by 2 to process the next bit
        s[i] = x + '0'; // Converting the bit to a character and appending it to the binary string
        i++; // Incrementing the index i to move to the next position in the binary string
    }
    s[i] = '\0'; // Null-terminating the binary string
    
    // Initializing a counter ans to count the number of '1's in the binary representation
    int ans = 0;
    
    // Iterating through the binary string to count '1's
    for (int j = 0; j < i; j++) {
        if (s[j] == '1') { // Checking if the current character is '1'
            ans++; // Incrementing the count of '1's
        }
    }
    
    // Printing the total count of '1's in the binary representation
    printf("%d", ans); // Printing the count of '1's
    
    return 0; // Returning 0 to indicate successful execution of the program
}
