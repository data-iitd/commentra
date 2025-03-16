
#include <stdio.h>
#include <string.h>

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

int parse(char* ss) { // Function to parse the input string and calculate the logical expression
    int it = 0; // Initialize index of the input string
    char c = ss[it++]; // Read the next character from the input string
    if ('0' <= c && c <= '2') return c-'0'; // If character is a binary digit, convert it to an integer and return
    if (c == '-') return Not(parse(ss)); // If character is NOT, recursively call parse() and apply NOT

    int x = parse(ss); // Parse the first binary number
    c = ss[it++]; // Read the next character from the input string
    int y = parse(ss); // Parse the second binary number
    ++it; // Increment the index of the input string
    return c == '*'? And(x, y) : Or(x, y); // If character is AND, call And() function. Otherwise, call Or() function
}

int main() { // Main function
    char input[1000]; // Input string
    while (scanf("%s", input)!= EOF && strcmp(input, ".")!= 0) { // Read input until end of file is reached
        int a[3], cnt = 0; // Initialize the array a with values 0, 1, 2 and counter for counting the number of valid expressions
        for (int i = 0; i < 3; i++) { // Loop to generate all possible combinations of a
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    a[0] = i; a[1] = j; a[2] = k;
                    char ss[1000]; // String for parsing
                    for (int l = 0; input[l]!= '\0'; l++) { // Replace P, Q, R with the values of a, b, c respectively
                        if (input[l] == 'P') ss[l] = a[0]+'0';
                        if (input[l] == 'Q') ss[l] = a[1]+'0';
                        if (input[l] == 'R') ss[l] = a[2]+'0';
                        ss[l+1] = '\0';
                    }
                    if (parse(ss) == 2) cnt++; // If the logical expression is valid, increment the counter
                }
            }
        }
        printf("%d\n", cnt); // Print the number of valid expressions for the current input
    }
}

