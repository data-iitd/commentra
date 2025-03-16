#include <stdio.h>
#include <string.h>

int main() {
    // Read the two strings S and T from standard input
    char S[1001], T[1001]; // Assuming maximum length of strings is 1000
    scanf("%s", S);
    scanf("%s", T);
    
    // Initialize the maximum number of matching characters to 0
    int max = 0;
<<<<<<< HEAD
=======
    
    // Get the lengths of the strings
>>>>>>> 98c87cb78a (data updated)
    int lenS = strlen(S);
    int lenT = strlen(T);
    
    // Iterate over the possible starting positions of the substring of S that is the same length as T
    for (int i = 0; i <= lenS - lenT; i++) {
        // Initialize a counter for the number of matching characters in the current substring
        int c = 0;
        
        // Check each character in the current substring against the corresponding character in T
        for (int j = 0; j < lenT; j++) {
            if (S[i + j] == T[j]) {
                // Increment the counter if the characters match
                c++;
            }
        }
        
        // Update max if the current count of matching characters is greater than the previous max
        if (max < c) {
            max = c;
        }
    }
    
    // Print the number of characters that need to be changed to make S contain T as a substring
    printf("%d\n", lenT - max);
    
    return 0;
}

/* <END-OF-CODE> */
