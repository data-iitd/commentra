#include <stdio.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000 // Initial buffer size
#define MAX_BUF_SIZE 100000000 // Maximum buffer size

// Function to find minimum of two integers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// Main function
int main() {
    // Read input string S
    char S[INITIAL_BUF_SIZE];
    fgets(S, sizeof(S), stdin);
    
    // Remove newline character if present
    S[strcspn(S, "\n")] = 0;

    // Initialize variables l0 and l1 to store count of '0' and '1' respectively
    int l0 = 0, l1 = 0;

    // Iterate through each character in string S
    for (int i = 0; i < strlen(S); i++) {
        // If current character is '0', increment l0
        if (S[i] == '0') {
            l0++;
        } else {
            // Otherwise, increment l1
            l1++;
        }
    }

    // Print result which is twice the minimum of l0 and l1
    printf("%d\n", 2 * min(l0, l1));

    return 0;
}
// <END-OF-CODE>
