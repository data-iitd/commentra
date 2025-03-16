#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", S);
    
    int count[256] = {0}; // Array to count occurrences of each character
    int uniqueCount = 0; // To count unique characters
    int length = strlen(S);
    
    // Count occurrences of each character
    for (int i = 0; i < length; i++) {
        if (count[(unsigned char)S[i]] == 0) {
            uniqueCount++;
        }
        count[(unsigned char)S[i]]++;
    }
    
    // Check if there are exactly 2 unique characters
    if (uniqueCount != 2) {
        printf("No\n");
        return 0;
    }
    
    // Check if each character appears exactly 2 times
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0 && count[i] != 2) {
            printf("No\n");
            return 0;
        }
    }
    
    printf("Yes\n");
    return 0;
}

// <END-OF-CODE>
