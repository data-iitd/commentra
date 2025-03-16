#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for atoi function
#include <string.h> // Including string library for string manipulation

int main() {
    long a; // Variable to store the long integer 'a'
    char b[100]; // Array to store the string 'b'
    
    scanf("%ld", &a); // Reading a long integer 'a' from the input
    scanf("%s", b); // Reading a string 'b' from the input
    
    char bStr[100]; // Array to store the filtered characters of 'b'
    int j = 0; // Index for bStr
    
    // Looping through the string 'b' to build the string 'bStr' without periods
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] != '.') {
            bStr[j++] = b[i]; // Appending non-period characters to 'bStr'
        }
    }
    bStr[j] = '\0'; // Null-terminating the string 'bStr'
    
    int bInt = atoi(bStr); // Converting 'bStr' to an integer
    long result = (a * bInt) / 100; // Calculating the result of (a * bInt) / 100
    printf("%ld\n", result); // Printing the result to the standard output
    
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
