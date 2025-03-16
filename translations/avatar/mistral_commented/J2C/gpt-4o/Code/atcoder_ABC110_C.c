#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    // Initialize variables to store input strings
    char S[100], T[100]; // Assuming maximum length of input strings is 99 characters
    bool res = true; // Initialize a boolean variable to store the result of the comparison

    // Read the first input line from the console
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = 0; // Remove the newline character

    // Read the second input line from the console
    fgets(T, sizeof(T), stdin);
    T[strcspn(T, "\n")] = 0; // Remove the newline character

    // Initialize an array of characters A with all possible characters from a to z
    char A[] = "abcdefghijklmnopqrstuvwxyz";

    // Iterate through each character in the array A
    for (int i = 0; i < 26; i++) {
        char s = A[i]; // Current character from A
        char t = '\0'; // Variable to store corresponding character from T
        int sIdx = strchr(S, s) ? strchr(S, s) - S : -1; // Find the index of character s in string S

        // If character s is not found in string S, continue to the next character
        if (sIdx < 0) continue;

        // Get the corresponding character from T
        t = T[sIdx];

        // Initialize an index variable idx to 0
        int idx = 0;

        // Iterate through each character in string S starting from the index sIdx
        while (idx < strlen(S)) {
            // Find the next occurrence of character s in string S starting from idx
            char *sPos = strchr(S + idx, s);
            char *tPos = strchr(T + idx, t);

            // If character s is found in string S
            if (sPos) {
                // If the corresponding character in T does not match, set res to false and break
                if (tPos == NULL || (sPos - S) != (tPos - T)) {
                    res = false;
                    break;
                } else {
                    // If the characters match, increment idx to the next position
                    idx = sPos - S + 1;
                }
            } else {
                // If character s is not found in S, break the loop
                break;
            }
        }

        // If res is still true after the loop, print "Yes"
        if (res) {
            printf("Yes\n");
        } else {
            // If res is false, print "No" and break out of the main loop
            printf("No\n");
            break;
        }
    }

    return 0;
}
