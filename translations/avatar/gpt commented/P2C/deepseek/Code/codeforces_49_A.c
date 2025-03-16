#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    char vo[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    int i, len;

    // Take input from the user
    fgets(a, sizeof(a), stdin);

    // Get the length of the input string
    len = strlen(a);

    // Iterate through the input string in reverse order
    for (i = len - 1; i >= 0; i--) {
        // Check if the current character is a space or a question mark
        if (a[i] == ' ' || a[i] == '?') {
            continue;  // Skip to the next iteration if it is a space or '?'
        } else {
            // Check if the current character is a vowel
            int is_vowel = 0;
            for (int j = 0; j < 12; j++) {
                if (a[i] == vo[j]) {
                    is_vowel = 1;
                    break;
                }
            }
            if (is_vowel) {
                printf("YES\n");  // Print "YES" if it is a vowel
            } else {
                printf("NO\n");   // Print "NO" if it is not a vowel
            }
            break;  // Exit the loop after processing the first non-space character
        }
    }

    return 0;
}
