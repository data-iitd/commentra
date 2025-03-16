#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains_digits(const char *s) {
    return strchr(s, '3') && strchr(s, '5') && strchr(s, '7');
}

void reverse_and_replace(char *s) {
    int len = strlen(s);
    char result[len + 1];
    int f = 0;

    for (int j = 0; j < len; j++) {
        char a = s[len - 1 - j];

        if (f) {
            result[j] = a; // Append the current character
        } else {
            if (a == '3') {
                result[j] = '5';
                f = 1;
            } else if (a == '5') {
                result[j] = '7';
                f = 1;
            } else {
                result[j] = '3';
                f = 1;
            }
        }
    }

    if (!f) {
        result[0] = '3'; // If no 3, 5, or 7 found, append a 3
    }

    result[len] = '\0'; // Null-terminate the string
    strcpy(s, result); // Copy the result back to the original string
}

int main() {
    long N;
    printf("Enter a number: ");
    scanf("%ld", &N); // Getting the value of N from user input

    long i = 357; // Initializing the variable i with a value of 357
    int c = 0; // Initializing the variable c with a value of 0

    while (i <= N) { // Starting a while loop that continues as long as i is less than or equal to N
        char s[20]; // Buffer to hold the string representation of i
        sprintf(s, "%ld", i); // Converting the integer value of i to a string

        if (contains_digits(s)) { // Checking if the string contains the digits 3, 5, and 7
            c++; // Incrementing the value of c by 1 if the condition is true
        }

        reverse_and_replace(s); // Reverse and replace digits in the string
        i = strtol(s, NULL, 10); // Converting the modified string back to a long integer
    }

    printf("%d\n", c); // Printing the value of c to the console
    return 0;
}

// <END-OF-CODE>
