#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    // Reading two lines of input: S and T
    char S[100], T[100];
    fgets(S, sizeof(S), stdin);
    fgets(T, sizeof(T), stdin);
    
    // Removing the newline character from the input strings
    S[strcspn(S, "\n")] = 0;
    T[strcspn(T, "\n")] = 0;

    // Defining an array of lowercase letters from 'a' to 'z'
    char A[26] = "abcdefghijklmnopqrstuvwxyz";
    
    // Initializing a boolean variable to track the result
    bool res = true;
    
    // Iterating through each letter in the array A
    for (int i = 0; i < 26; i++) {
        char s = A[i];
        
        // Finding the index of the current letter in string S
        char *sPtr = strchr(S, s);
        
        // If the letter is not found in S, continue to the next letter
        if (sPtr == NULL) continue;
        
        // Getting the index of the found character in S
        int sIdx = sPtr - S;
        char t = T[sIdx]; // Getting the corresponding character from T at the same index
        int idx = 0; // Initializing index for searching
        
        // Loop to check the correspondence of characters in S and T
        while (idx < strlen(S)) {
            // If the current letter s is found in S starting from idx
            sPtr = strchr(S + idx, s);
            if (sPtr != NULL) {
                // Check if the index of s in S matches the index of t in T
                if (sPtr - S != strchr(T + idx, t) - T) {
                    // If they do not match, set res to false and break
                    res = false;
                    break;
                } else {
                    // If they match, move the index to the next position
                    idx = sPtr - S + 1;
                }
            } 
            // If the character t is found in T but s is not found in S
            else if (strchr(T + idx, t) != NULL) {
                // Set res to false and break
                res = false;
                break;
            } else {
                // Break the loop if neither character is found
                break;
            }
        }
        // If a mismatch was found, break out of the outer loop
        if (!res) break;
    }
    
    // Output the result based on the value of res
    if (res) 
        printf("Yes\n"); // If res is true, print "Yes"
    else 
        printf("No\n"); // If res is false, print "No"

    return 0;
}
