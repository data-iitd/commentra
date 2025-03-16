#include <stdio.h>
#include <stdlib.h>

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    a = (a > b) ? a : b;
    b = (a > b) ? b : a;
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

// Main function to solve the problem
void solve() {
    char s[100001];
    scanf("%s", s);  // Read input string
    char t[100001] = "";  // Initialize an empty string to store processed characters
    int i = 0;  // Initialize index
    
    // Process the input string character by character
    while (s[i] != '\0') {
        if (s[i] == 'A') {
            t[i] = 'A';
            i++;
        } else if (s[i] == 'B') {
            if (i < strlen(s) - 1) {
                if (s[i + 1] == 'C') {
                    t[i] = 'D';
                    i += 2;
                } else {
                    t[i] = 'X';
                    i++;
                }
            } else {
                t[i] = 'X';
                i++;
            }
        } else {
            t[i] = 'X';
            i++;
        }
    }
    t[i] = '\0';  // Null-terminate the processed string
    
    int total = 0;  // Initialize total count
    int numA = 0;  // Initialize count of 'A' characters
    
    // Count the number of 'A' characters before each 'X' in the processed string
    for (i = 0; t[i] != '\0'; i++) {
        if (t[i] == 'X') {
            numA = 0;
        } else {
            if (t[i] == 'A') {
                numA++;
            } else {
                total += numA;
            }
        }
    }
    
    printf("%d\n", total);  // Print the total count
    
    // Define constants for infinity and modulo
    const long long INF = 1e25;
    const int mod = 7 + 10e9;
}

// Check if the script is being run as the main module
int main() {
    solve();
    return 0;
}
