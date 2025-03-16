#include <stdio.h>
#include <string.h>

int main() {
    // Creating a Scanner object to read input from the console
    char S[100], T[100];
    scanf("%s", S);
    scanf("%s", T);
    
    // Defining an array of lowercase letters from 'a' to 'z'
    char A[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    // Initializing a boolean variable to track the result
    int res = 1;
    
    // Iterating through each letter in the array A
    for (int i = 0; i < 26; i++) {
        // Finding the index of the current letter in string S
        int sIdx = strchr(S, A[i]) - S;
        
        // If the letter is not found in S, continue to the next letter
        if (sIdx < 0) continue;
        
        // Getting the corresponding character from T at the same index
        char t = T[sIdx];
        int idx = 0; // Initializing index for searching
        
        // Loop to check the correspondence of characters in S and T
        while (idx < strlen(S)) {
            // If the current letter s is found in S starting from idx
            if (strchr(S + idx, A[i]) != NULL) {
                // Check if the index of s in S matches the index of t in T
                if (strchr(S + idx, A[i]) - S != strchr(T + idx, t) - T) {
                    // If they do not match, set res to false and break
                    res = 0;
                    break;
                } else {
                    // If they match, move the index to the next position
                    idx = strchr(S + idx, A[i]) - S + 1;
                }
            } 
            // If the character t is found in T but s is not found in S
            else if (strchr(T + idx, t) != NULL) {
                // Set res to false and break
                res = 0;
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

