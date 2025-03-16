#include <stdio.h>
#include <string.h>

int main() {
    char a[100];  // Define a character array to store the input
    char vo[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};  // Define a string of vowels
    int i, len;

    // Take an input from the user
    fgets(a, sizeof(a), stdin);

    // Get the length of the input string
    len = strlen(a);

    // Iterate over the input string in reverse order
    for (i = len - 1; i >= 0; i--) {
        if (a[i] == ' ' || a[i] == '?' || a[i] == '\n') {  // Check if the current character is a space, question mark, or newline
            continue;  // Continue to the next iteration
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
                printf("YES\n");  // Print "YES" if the character is a vowel
            } else {
                printf("NO\n");  // Print "NO" if the character is not a vowel
            }
            break;  // Break the loop after printing the result
        }
    }

    return 0;
}
