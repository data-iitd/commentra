#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int main() {
    char str[100001]; // Assuming the maximum length of the input string is 100000
    int charCount[MAX_CHAR] = {0}; // Array to count occurrences of each character
    int oddCount = 0;

    // Read the input string
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character if present

    // Count occurrences of each character
    for (int i = 0; str[i] != '\0'; i++) {
        charCount[(unsigned char)str[i]]++;
    }

    // Count how many characters have an odd count
    for (int i = 0; i < MAX_CHAR; i++) {
        if (charCount[i] % 2 != 0) {
            oddCount++;
        }
    }

    // Determine the result based on the oddCount
    if (oddCount <= 1 || oddCount % 2 != 0) {
        printf("First\n");
    } else {
        printf("Second\n");
    }

    return 0;
}

// <END-OF-CODE>
