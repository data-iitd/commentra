
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Declare a character array to store the input string
    printf("Enter a string: ");  // Prompt the user to enter a string
    fgets(s, sizeof(s), stdin);  // Read the input string from the user
    int len = strlen(s);  // Get the length of the input string
    char res[len];  // Declare a character array to store the result
    int j = 0;  // Initialize an index variable for the result array
    char punctuation[] = ",.!?";  // Define a string of punctuation marks
    int p_len = strlen(punctuation);  // Get the length of the punctuation string

    // Iterate over each character in the input string
    for (int i = 0; i < len; i++) {
        if (i >= 1) {  // Check if it's not the first character
            if (s[i] =='') {  // Check if the current character is a space
                if (res[j - 1]!='') {  // Check if the last character in res is not a space
                    res[j++] = s[i];  // Append the current space to res
                } else {
                    continue;  // Skip the current space if the last character is also a space
                }
            } else {  // If the current character is not a space
                int found = 0;  // Initialize a flag variable to check if the current character is a punctuation mark
                for (int k = 0; k < p_len; k++) {
                    if (s[i] == punctuation[k]) {  // Check if the current character is a punctuation mark
                        found = 1;  // Set the flag variable to 1 if the current character is a punctuation mark
                        break;  // Exit the loop if the current character is a punctuation mark
                    }
                }
                if (found) {  // If the current character is a punctuation mark
                    if (res[j - 1] =='') {  // Check if the last character in res is a space
                        res[--j] = '\0';  // Remove the last character (space) from res
                    }
                    res[j++] = s[i];  // Append the punctuation mark to res
                    res[j++] ='';  // Append a space after the punctuation mark
                } else {
                    res[j++] = s[i];  // Append the character to res if it's not a punctuation mark
                }
            }
        } else {  // For the first character
            if (s[i] =='') {  // Check if the first character is a space
                continue;  // Skip the first space
            }
            if (strchr(punctuation, s[i])) {  // Check if the first character is a punctuation mark
                continue;  // Skip the first punctuation mark
            } else {
                res[j++] = s[i];  // Append the first character to res
            }
        }
    }

    // Print the result
    res[j] = '\0';  // Null-terminate the result string
    printf("Result: %s\n", res);

    return 0;
}
