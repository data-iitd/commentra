#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DIVIDE 4
#define MAX_LENGTH 10

// Initialize an array of strings called divide
const char *divide[MAX_DIVIDE] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    // Declare a string variable called S and read a string from the standard input
    char S[MAX_LENGTH];
    scanf("%s", S);

    // Reverse the string S
    int len = strlen(S);
    for (int i = 0; i < len / 2; ++i) {
        char temp = S[i];
        S[i] = S[len - 1 - i];
        S[len - 1 - i] = temp;
    }

    // Reverse each string in the divide array
    char reversed_divide[MAX_DIVIDE][MAX_LENGTH];
    for (int i = 0; i < MAX_DIVIDE; ++i) {
        int d_len = strlen(divide[i]);
        for (int j = 0; j < d_len; ++j) {
            reversed_divide[i][j] = divide[i][d_len - 1 - j];
        }
        reversed_divide[i][d_len] = '\0'; // Null-terminate the string
    }

    // Initialize a boolean variable called can to true
    bool can = true;

    // Iterate through each character in the string S
    for (int i = 0; i < len;) {
        // Initialize a boolean variable called can2 to false
        bool can2 = false;

        // Iterate through each string in the divide array
        for (int j = 0; j < MAX_DIVIDE; ++j) {
            // Get the string d from the reversed divide array
            const char *d = reversed_divide[j];
            int d_len = strlen(d);

            // Check if the substring of S starting from the current index i and having the same size as d is equal to d
            if (strncmp(&S[i], d, d_len) == 0) {
                // If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
                can2 = true;
                i += d_len;
                break; // Break the inner loop since we found a match
            }
        }

        // If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
        if (!can2) {
            can = false;
            break;
        }
    }

    // Output "YES" if can is true, otherwise output "NO"
    if (can) printf("YES\n");
    else printf("NO\n");

    return 0;
}

// <END-OF-CODE>
