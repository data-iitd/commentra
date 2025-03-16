#include <stdio.h>
#include <string.h>

void ReadString(char *str, int maxLength) {
    fgets(str, maxLength, stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character
}

int main() {
    char S[100], T[100]; // Assuming maximum length of strings is 100
    ReadString(S, sizeof(S));
    ReadString(T, sizeof(T));
    
    int max = 0; // Variable to keep track of the maximum number of matching characters
    int lenS = strlen(S);
    int lenT = strlen(T);
    
    // Iterate over each possible starting index in S where T can fit
    for (int i = 0; i <= lenS - lenT; i++) {
        int c = 0; // Counter for matching characters
        
        // Compare characters of T with the corresponding characters in S
        for (int j = 0; j < lenT; j++) {
            if (S[i + j] == T[j]) {
                c++; // Increment the counter for each matching character
            }
        }
        
        // Update the maximum count of matching characters if the current count is greater
        if (max < c) {
            max = c;
        }
    }
    
    // Output the number of characters in T that do not match with S
    printf("%d\n", lenT - max);
    
    return 0;
}

// <END-OF-CODE>
