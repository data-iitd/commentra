#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10000000  // Define a maximum length for the input string

// Function to read an integer from input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a string from input
void read_string(char *s) {
    scanf("%s", s);
}

// Main function to execute the program
int main() {
    char s[MAX_LENGTH];  // Declare a string to hold the input
    read_string(s);  // Read the input string
    int k = read_int();  // Read the integer k
    int l = 0;  // Initialize a counter for leading '1's

    // Loop through each character in the string
    while (s[l] == '1') {
        l++;  // Increment the counter for each '1' found
    }

    // Check if the number of leading '1's is greater than or equal to k
    if (l >= k) {
        printf("1\n");  // Print 1 if true
    } else {
        printf("%c\n", s[l]);  // Print the character at the position of the first non-'1' character
    }

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
