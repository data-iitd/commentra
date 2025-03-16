

#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library

int main() {
    long a; // Declaring a long integer variable 'a'
    char b[1000]; // Declaring a character array variable 'b' with a maximum length of 1000
    fgets(b, 1000, stdin); // Reading a string from the standard input stream and storing it in 'b'
    char *bPtr = b; // Declaring a pointer variable 'bPtr' to traverse the string 'b'
    char *bPtrEnd = b + strlen(b); // Declaring a pointer variable 'bPtrEnd' to mark the end of the string 'b'
    char *bPtrFilter = b; // Declaring a pointer variable 'bPtrFilter' to store the filtered characters of 'b'
    while (bPtr < bPtrEnd) {
        if (*bPtr!= '.') { // Checking if the current character is not a period
            *bPtrFilter = *bPtr; // Copying the non-period character to the filtered string
            bPtrFilter++; // Incrementing the filtered string pointer
        }
        bPtr++; // Incrementing the original string pointer
    }
    *bPtrFilter = '\0'; // Null-terminating the filtered string
    int bInt = atoi(b); // Parsing the filtered string as an integer
    long result = (a * bInt) / 100; // Calculating the result of (a * bInt) / 100
    printf("%ld\n", result); // Printing the result to the standard output stream
    return 0; // Returning 0 to indicate successful execution
}
