#include <stdio.h>
#include <string.h>

int main() {
    char S[1000], T[1000];
    char *A[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int i, j, k;
    int res = 1;

    // Read the first input line from the console
    fgets(S, sizeof(S), stdin);

    // Read the second input line from the console
    fgets(T, sizeof(T), stdin);

    // Remove newline character from the end of the strings
    S[strcspn(S, "\n")] = 0;
    T[strcspn(T, "\n")] = 0;

    // Iterate through each string s in the array A
    for (i = 0; i < 26; i++) {
        // Find the index of string s in string S
        int sIdx = strstr(S, A[i]) - S;

        // If string s is not found in string S, continue to the next string in the array
        if (sIdx < 0) continue;

        // Convert the character at the index sIdx in string T to a string
        char t = T[sIdx];

        // Initialize an index variable idx to 0
        int idx = 0;

        // Iterate through each character in string S starting from the index sIdx
        while (idx < strlen(S)) {
            // If string s is found in string S starting from index idx, compare the corresponding characters in strings S and T
            if (strstr(&S[idx], A[i]) != NULL) {
                if (strstr(&S[idx], A[i]) - &S[0] != strstr(&T[idx], &t)) {
                    // If the characters do not match, set the boolean variable res to false and break out of the loop
                    res = 0;
                    break;
                } else {
                    // If the characters match, increment the index variable idx by the length of string s
                    idx = strstr(&S[idx], A[i]) - &S[0] + 1;
                }
            }

            // If string s is not found in string T starting from index idx, set the boolean variable res to false and break out of the loop
            else if (strstr(&T[idx], &t) != NULL) {
                res = 0;
                break;
            }

            // If string s is not found in both strings S and T starting from index idx, break out of the loop
            else break;
        }

        // If the boolean variable res is still true after the loop, print "Yes" to the console
        if (res) printf("Yes\n");

        // If the boolean variable res is false, print "No" to the console and break out of the main loop
        else {
            printf("No\n");
            break;
        }
    }

    return 0;
}
