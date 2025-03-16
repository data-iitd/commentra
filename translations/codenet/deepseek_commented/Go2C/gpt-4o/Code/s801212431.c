#include <stdio.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000

// Returns the minimum of two integers.
int min(int x, int y) {
    return (x < y) ? x : y;
}

// Main function to execute the program logic.
int main() {
    char S[INITIAL_BUF_SIZE];
    
    // Read the input string
    fgets(S, sizeof(S), stdin);
    
    // Remove the newline character if present
    S[strcspn(S, "\n")] = 0;

    // Initialize counters for '0's and '1's
    int l0 = 0, l1 = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '0') {
            l0++;
        } else {
            l1++;
        }
    }
    
    printf("%d\n", 2 * min(l0, l1));
    return 0;
}

// <END-OF-CODE>
