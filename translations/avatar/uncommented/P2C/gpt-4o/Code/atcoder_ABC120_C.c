#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000000

int main() {
    char s[MAX_LEN];
    scanf("%s", s);
    
    int count[256] = {0}; // To count occurrences of each character
    int unique_chars = 0;
    
    // Count occurrences of each character
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[(unsigned char)s[i]] == 0) {
            unique_chars++;
        }
        count[(unsigned char)s[i]]++;
    }
    
    // If all characters are the same
    if (unique_chars == 1) {
        printf("0\n");
        return 0;
    }
    
    // Find the minimum count of any character
    int min_count = MAX_LEN;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0 && count[i] < min_count) {
            min_count = count[i];
        }
    }
    
    // The answer is twice the minimum count
    printf("%d\n", min_count * 2);
    
    return 0;
}

// <END-OF-CODE>
