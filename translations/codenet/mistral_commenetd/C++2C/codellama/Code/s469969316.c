#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define rep(i,n) for (int i = 0; i < int(n); i++) // Macro for repetition of a loop n times

char input[1000], ss[1000]; // Input string and string for parsing
int a[3], it, cnt; // Arrays and counters

int Not(int x) { // Function to calculate NOT of a binary number
    return 2-x;
}

int And(int x, int y) { // Function to calculate AND of two binary numbers
    if (x*y == 0) return 0; // If product of x and y is zero, return zero
    if (x == 2 && y == 2) return 2; // If both x and y are 2, return 2
    return 1; // Otherwise, return 1
}

int Or(int x, int y) { // Function to calculate OR of two binary numbers
    if (x == 2 || y == 2) return 2; // If either x or y is 2, return 2
    if (x == 1 || y == 1) return 1; // If either x or y is 1, return 1
    return 0; // Otherwise, return 0
}

int parse() { // Function to parse the input string and calculate the logical expression
    char c = ss[it++]; // Read the next character from the input string
    if ('0' <= c && c <= '2') return c-'0'; // If character is a binary digit, convert it to an integer and return
    if (c == '-') return Not(parse()); // If character is NOT, recursively call parse() and apply NOT

    int x = parse(); // Parse the first binary number
    c = ss[it++]; // Read the next character from the input string
    int y = parse(); // Parse the second binary number
    ++it; // Increment the index of the input string
    return c == '*' ? And(x, y) : Or(x, y); // If character is AND, call And() function. Otherwise, call Or() function
}

int main() { // Main function
    while (scanf("%s", input) == 1 && strcmp(input, ".") != 0) { // Read input until end of file is reached
        rep (i,3) a[i] = i; // Initialize the array a with values 0, 1, 2
        cnt = 0; // Initialize counter for counting the number of valid expressions
        rep (i,3) rep (j,3) rep (k,3) { // Nested loop to generate all possible combinations of a, b, c
            a[0] = i; a[1] = j; a[2] = k;
            strcpy(ss, input); // Set the input string for the current combination
            for (int i = 0; ss[i] != '\0'; i++) { // Replace P, Q, R with the values of a, b, c respectively
                if (ss[i] == 'P') ss[i] = a[0]+'0';
                if (ss[i] == 'Q') ss[i] = a[1]+'0';
                if (ss[i] == 'R') ss[i] = a[2]+'0';
            }
            it = 0; // Reset the index of the input string
            if (parse() == 2) cnt++; // If the logical expression is valid, increment the counter
        }
        printf("%d\n", cnt); // Print the number of valid expressions for the current input
    }
}

