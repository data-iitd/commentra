#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    int dt[256] = {0}; // Array to count occurrences of each character
    int cnt = 0;
    int x = 1; // True

    // Read input
    scanf("%s", s);
    
    // Count occurrences of each character
    for (int i = 0; s[i] != '\0'; i++) {
        dt[(unsigned char)s[i]]++;
    }

    // Check for odd occurrences
    for (int i = 0; i < 256; i++) {
        if (dt[i] % 2 != 0) {
            if (cnt < 1) {
                cnt++;
            } else {
                x = 0; // False
                break;
            }
        }
    }

    // Determine the output based on the conditions
    if (x) {
        printf("First\n");
    } else if (!x && strlen(s) % 2 == 0) {
        printf("Second\n");
    } else if (!x && strlen(s) % 2 != 0) {
        printf("First\n");
    }

    return 0;
}

// <END-OF-CODE>
