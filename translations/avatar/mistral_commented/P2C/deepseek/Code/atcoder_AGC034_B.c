#include <stdio.h>
#include <string.h>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Making 'a' greater than 'b'
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // Finding the GCD using Euclidean algorithm
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    
    // Returning the GCD
    return b;
}

// Function to solve the problem
void solve() {
    // Reading the input string from standard input
    char s[1000];
    scanf("%s", s);
    
    // Initializing an empty string 't' to store the output string
    char t[1000] = "";
    
    // Iterating through each character in the input string 's'
    int i = 0;
    while (s[i] != '\0') {
        // If the current character is 'A', append 'A' to 't' and move to the next character
        if (s[i] == 'A') {
            strncat(t, "A", 1);
            i++;
        }
        // If the current character is 'B', check if the next character is 'C'. If yes, append 'D' to 't' and move to the next character (two steps ahead). If no, append 'X' to 't' and move to the next character
        else if (s[i] == 'B') {
            if (s[i + 1] != '\0') {
                if (s[i + 1] == 'C') {
                    strncat(t, "D", 1);
                    i += 2;
                } else {
                    strncat(t, "X", 1);
                    i++;
                }
            } else {
                strncat(t, "X", 1);
                i++;
            }
        }
        // If the current character is not 'A' or 'B', append 'X' to 't' and move to the next character
        else {
            strncat(t, "X", 1);
            i++;
        }
    }
    
    // Initializing variables 'total' and 'numA' to 0
    int total = 0;
    int numA = 0;
    
    // Iterating through each character in the output string 't'
    for (i = 0; i < strlen(t); i++) {
        // If the current character is 'X', reset 'numA' to 0
        if (t[i] == 'X') {
            numA = 0;
        }
        // If the current character is 'A', increment 'numA' by 1
        else if (t[i] == 'A') {
            numA++;
        }
        // Adding the product of the number of 'A's in the current segment and the previous segment to 'total'
        total += numA;
    }
    
    // Printing the final answer
    printf("%d\n", total);
}

// Starting the program if the script is run directly
int main() {
    // Calling the 'solve' function
    solve();
    return 0;
}
