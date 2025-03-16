#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Array to store the input string
    int dt[256] = {0};  // Array to store character frequencies (ASCII size)
    int cnt = 0;  // Counter for characters with odd frequency
    int x = 1;  // Boolean variable to track the result

    // Read the input string
    scanf("%s", s);

    // Iterate over each character in the input string and update the frequency count in the array
    for (int i = 0; s[i] != '\0'; i++) {
        dt[(unsigned char)s[i]]++;  // Increment the frequency of the character
    }

    // Iterate over the frequency array to determine if there is more than one character with an odd frequency
    for (int i = 0; i < 256; i++) {
        if (dt[i] % 2 != 0) {
            cnt++;
            if (cnt > 1) {
                x = 0;  // Set x to false if more than one character has an odd frequency
                break;
            }
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
}  // <END-OF-CODE>
