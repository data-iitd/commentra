
#include <stdio.h>
#include <string.h>

// Macro to simplify loop syntax
#define rep(i,n) for (int i = 0; i < int(n); i++)

// Global variables for input and state management
char input[1000], ss[1000];
int a[3], it, cnt;

// Function to compute the NOT operation
int Not(int x) {
    return 2 - x; // Returns the negation of the input value
}

// Function to compute the AND operation
int And(int x, int y) {
    if (x * y == 0) return 0; // If either input is 0, return 0
    if (x == 2 && y == 2) return 2; // If both inputs are 2, return 2
    return 1; // Otherwise, return 1
}

// Function to compute the OR operation
int Or(int x, int y) {
    if (x == 2 || y == 2) return 2; // If either input is 2, return 2
    if (x == 1 || y == 1) return 1; // If either input is 1, return 1
    return 0; // Otherwise, return 0
}

// Recursive function to parse the expression and evaluate it
int parse() {
    char c = ss[it++]; // Get the current character from the string
    if ('0' <= c && c <= '2') return c - '0'; // Return the numeric value if it's a digit
    if (c == '-') return Not(parse()); // Handle NOT operation

    // Parse left operand
    int x = parse();
    c = ss[it++]; // Get the operator
    // Parse right operand
    int y = parse();
    ++it; // Move past the closing parenthesis
    // Return the result of the operation based on the operator
    return c == '*'? And(x, y) : Or(x, y);
}

// Main function to read input and evaluate expressions
int main() {
    // Loop until the input is a single dot (.)
    while (scanf("%s", input)!= EOF && input[0]!= '.') {
        // Initialize the truth values for P, Q, R
        rep(i, 3) a[i] = i; 
        cnt = 0; // Initialize the count of valid evaluations

        // Iterate through all combinations of truth values for P, Q, R
        rep(i, 3) rep(j, 3) rep(k, 3) {
            a[0] = i; a[1] = j; a[2] = k; // Assign truth values to P, Q, R
            strcpy(ss, input); // Copy the input expression for processing

            // Replace variables P, Q, R in the expression with their truth values
            for (char* p = ss; *p; p++) {
                if (*p == 'P') *p = a[0] + '0'; // Replace P with its truth value
                if (*p == 'Q') *p = a[1] + '0'; // Replace Q with its truth value
                if (*p == 'R') *p = a[2] + '0'; // Replace R with its truth value
            }

            it = 0; // Reset the index for parsing
            // Evaluate the expression and count if it evaluates to true (2)
            if (parse() == 2) cnt++;
        }
        // Output the count of valid evaluations
        printf("%d\n", cnt);
    }
}
