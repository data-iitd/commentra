#include <stdio.h>
#include <string.h>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Making 'a' greater than 'b'
    if (b > a) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // Finding the GCD using Euclidean algorithm
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    // Returning the GCD
    return a;
}

// Function to solve the problem
void solve() {
    // Reading the input string
    char s[100000]; // Assuming a maximum length for the input string
    scanf("%s", s);
    
    // Initializing an empty string 't' to store the output string
    char t[100000];
    int t_index = 0;
    
    // Iterating through each character in the input string 's'
    int i = 0;
    while (s[i] != '\0') {
        // If the current character is 'A', append 'A' to 't' and move to the next character
        if (s[i] == 'A') {
            t[t_index++] = 'A';
            i++;
        }
        // If the current character is 'B', check if the next character is 'C'
        else if (s[i] == 'B') {
            if (s[i + 1] == 'C') {
                t[t_index++] = 'D';
                i += 2;
            } else {
                t[t_index++] = 'X';
                i++;
            }
        }
        // If the current character is not 'A' or 'B', append 'X' to 't'
        else {
            t[t_index++] = 'X';
            i++;
        }
    }
    t[t_index] = '\0'; // Null-terminate the output string
    
    // Initializing variables 'total' and 'numA' to 0
    int total = 0;
    int numA = 0;
    
    // Iterating through each character in the output string 't'
    for (i = 0; i < t_index; i++) {
        // If the current character is 'X', reset 'numA' to 0
        if (t[i] == 'X') {
            numA = 0;
        }
        // If the current character is 'A', increment 'numA' by 1
        else if (t[i] == 'A') {
            numA++;
        }
        // Adding the product of the number of 'A's in the current segment to 'total'
        total += numA;
    }
    
    // Printing the final answer
    printf("%d\n", total);
}

// Starting the program
int main() {
    // Calling the 'solve' function
    solve();
    return 0;
}

// <END-OF-CODE>
