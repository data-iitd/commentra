
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long a; // Declaring a long integer 'a'
    char b[100]; // Declaring a character array 'b' of size 100
    int length; // Declaring an integer 'length'
    char bStr[100]; // Declaring a character array 'bStr' of size 100
    int i; // Declaring an integer 'i'
    long result; // Declaring a long integer 'result'
    
    scanf("%ld", &a); // Reading a long integer 'a' from the standard input stream
    scanf("%s", b); // Reading a string 'b' from the standard input stream
    
    length = strlen(b); // Getting the length of the character array 'b'
    for (i = 0; i < length; i++) { // Looping through the character array 'b'
        if (b[i] != '.') { // Checking if the current character is not a period
            bStr[i] = b[i]; // Appending the current character to 'bStr'
        }
    }
    
    bStr[i] = '\0'; // Appending a null character to 'bStr'
    int bInt = atoi(bStr); // Parsing 'bStr' as an integer
    result = (a * bInt) / 100; // Calculating the result of (a * bInt) / 100
    printf("%ld\n", result); // Printing the result to the standard output
    
    return 0;
}

