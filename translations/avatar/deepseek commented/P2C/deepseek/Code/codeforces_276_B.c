#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000];  // Declare a character array to store the input string
    int dt[256] = {0};  // Declare an array to store character frequencies, initialized to 0
    int cnt = 0;  // Initialize a counter to keep track of characters with an odd frequency
    int x = 1;  // Initialize a boolean variable to track the result

    // Read the input string
    fgets(s, sizeof(s), stdin);

    // Remove the newline character if present
    s[strcspn(s, "\n")] = '\0';

    // Iterate over each character in the input string and update the frequency count in the array
    for (int i = 0; i < strlen(s); i++) {
        dt[(int)s[i]]++;
    }

    // Iterate over the array to determine if there is more than one character with an odd frequency
    for (int i = 0; i < 256; i++) {
        if (dt[i] % 2 != 0 && cnt < 1) {
            cnt++;
        } else if (dt[i] % 2 != 0 && cnt >= 1) {
            x = 0;
            break;
        }
    }

    // Determine the output based on the value of cnt and the length of the input string
    if (x) {
        printf("First\n");  // Print "First" if there is at most one character with an odd frequency
    } else if (!x && strlen(s) % 2 == 0) {
        printf("Second\n");  // Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
    } else if (!x && strlen(s) % 2 != 0) {
        printf("First\n");  // Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
    }

    return 0;
}
