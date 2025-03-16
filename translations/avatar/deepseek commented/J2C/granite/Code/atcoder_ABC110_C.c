
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library

int main() {
    char S[101], T[101]; // Declare character arrays S and T with a maximum length of 100
    fgets(S, 101, stdin); // Read input string S
    fgets(T, 101, stdin); // Read input string T

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz"; // Array of all lowercase letters
    int A[26] = {0}; // Initialize an array A of size 26 to store the indices of the letters in S

    // Loop through each letter in the alphabet
    for (int i = 0; i < 26; i++) {
        char c = alphabet[i]; // Get the current letter
        A[i] = strchr(S, c) - S; // Find the index of the current letter in S and store it in A[i]
    }

    bool res = true; // Initialize result as true

    // Loop through each letter in the alphabet
    for (int i = 0; i < 26; i++) {
        char c = alphabet[i]; // Get the current letter
        int idx = A[i]; // Get the index of the current letter in S
        if (idx < 0) continue; // If the letter is not in S, continue to the next letter

        char t = T[idx]; // Find the corresponding letter in T

        int j = 0; // Initialize index for comparison
        while (j < strlen(S)) {
            if (strchr(S + j, c)!= NULL) { // If the letter appears in S from the current index
                if (strchr(S + j, c) - S!= strchr(T + j, t) - T) { // Check if the positions match
                    res = false; // If positions do not match, set res to false
                    break; // Break out of the loop
                } else {
                    j = strchr(S + j, c) - S + 1; // Update index to check the next position
                }
            } else if (strchr(T + j, t)!= NULL) { // If the letter appears in T from the current index
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

    return 0; // Return 0 to indicate successful execution
}
