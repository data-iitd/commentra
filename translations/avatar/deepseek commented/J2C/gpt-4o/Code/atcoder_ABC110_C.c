#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char S[100], T[100]; // Arrays to hold input strings
    fgets(S, sizeof(S), stdin); // Read input string S
    fgets(T, sizeof(T), stdin); // Read input string T

    // Remove newline character from the end of the strings if present
    S[strcspn(S, "\n")] = 0;
    T[strcspn(T, "\n")] = 0;

    char A[] = "abcdefghijklmnopqrstuvwxyz"; // String of all lowercase letters
    bool res = true; // Initialize result as true

    // Loop through each letter in the alphabet
    for (int i = 0; i < 26; i++) {
        char s = A[i]; // Current letter
        char t = T[strcspn(S, (char[]){s, '\0'})]; // Find the corresponding letter in T

        int idx = 0; // Initialize index for comparison
        while (idx < strlen(S)) {
            char *s_pos = strchr(S + idx, s); // Find the position of s in S from current index
            char *t_pos = strchr(T + idx, t); // Find the position of t in T from current index

            if (s_pos != NULL) { // If the letter appears in S
                if (s_pos - S != t_pos - T) { // Check if the positions match
                    res = false; // If positions do not match, set res to false
                    break; // Break out of the loop
                } else {
                    idx = s_pos - S + 1; // Update index to check the next position
                }
            } else if (t_pos != NULL) { // If the letter appears in T
                res = false; // If positions do not match, set res to false
                break; // Break out of the loop
            } else {
                break; // If neither letter appears, break out of the loop
            }
        }
        if (!res) break; // If res is false, break out of the outer loop
    }

    if (res) {
        printf("Yes\n"); // If res is true, print "Yes"
    } else {
        printf("No\n"); // If res is false, print "No"
    }

    return 0;
}

// <END-OF-CODE>
