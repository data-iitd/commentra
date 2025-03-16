

#include <stdio.h>
#include <string.h>

int main() {
    char a[100];  // Declare a character array to store the input string
    scanf("%s", a);  // Take an input from the user and store it in the array

    char vo[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};  // Define a character array of vowels
    int len = strlen(a);  // Get the length of the input string

    for (int i = len - 1; i >= 0; i--) {  // Iterate over the input string in reverse order
        if (a[i] =='' || a[i] == '?') {  // Check if the current character is a space or a question mark
            continue;  // Continue to the next iteration
        } else {
            if (strchr(vo, a[i])) {  // Check if the current character is a vowel
                printf("YES\n");  // Print "YES" if the character is a vowel
            } else {
                printf("NO\n");  // Print "NO" if the character is not a vowel and break the loop
            }
            break;  // Break the loop after printing the result
        }
    }

    return 0;
}
