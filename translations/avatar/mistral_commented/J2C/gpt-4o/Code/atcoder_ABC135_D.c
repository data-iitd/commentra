#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007 // Define the modulus value

// Function to run the program
void run() {
    char cs[100]; // Array to hold the input string (assuming max length of 100)
    scanf("%s", cs); // Read the input string
    int len = strlen(cs); // Get the length of the input string
    long dp[len][13]; // Create a 2D array dp of size len x 13 to store the intermediate results
    memset(dp, 0, sizeof(dp)); // Initialize the dp array to 0
    long base = 1; // Initialize the base variable to 1

    // Iterate through each character in the character array cs
    for (int i = 0; i < len; ++i) {
        if (cs[len - 1 - i] == '?') { // If the current character is a '?'
            for (int pre = 0; pre < 13; ++pre) { // Iterate through all possible values of pre (from 0 to 12)
                for (int next = 0; next < 10; ++next) { // Iterate through all possible values of next (from 0 to 9)
                    dp[i][(base * next + pre) % 13] += // Add the contribution of the current character to the dp array
                        (i > 0 ? dp[i - 1][pre] : // If i is not the first character, add the contribution of the previous character
                        (pre == 0 ? 1 : 0)); // If pre is 0, add a constant value of 1
                    dp[i][(base * next + pre) % 13] %= MOD; // Perform modulo operation to keep the result within the range of MOD
                }
            }
        } else { // If the current character is not a '?'
            int next = cs[len - 1 - i] - '0'; // Convert the digit character to an integer
            for (int pre = 0; pre < 13; ++pre) { // Iterate through all possible values of pre (from 0 to 12)
                dp[i][(base * next + pre) % 13] += // Add the contribution of the current character to the dp array
                    (i > 0 ? dp[i - 1][pre] : // If i is not the first character, add the contribution of the previous character
                    (pre == 0 ? 1 : 0)); // If pre is 0, add a constant value of 1
                dp[i][(base * next + pre) % 13] %= MOD; // Perform modulo operation to keep the result within the range of MOD
            }
        }
        base = base * 10 % 13; // Multiply the base by 10 and take the result modulo 13 to update the base for the next character
    }

    // Print the final result
    printf("%ld\n", dp[len - 1][5]);
}

int main() {
    run(); // Call the run function to start the execution
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
