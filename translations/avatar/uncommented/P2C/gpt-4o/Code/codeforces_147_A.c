#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1000]; // Assuming the input string will not exceed 999 characters
    fgets(s, sizeof(s), stdin);
    
    char *res[2000]; // To store the result, assuming a maximum of 2000 tokens
    int res_index = 0;
    char *punctuation[] = {",", ".", "!", "?"};
    
    for (int i = 0; i < strlen(s); i++) {
        if (i >= 1) {
            if (s[i] == ' ') {
                if (res_index > 0 && strcmp(res[res_index - 1], "") != 0) {
                    res[res_index++] = strdup(" ");
                }
            } else {
                int is_punctuation = 0;
                for (int j = 0; j < 4; j++) {
                    if (s[i] == *punctuation[j]) {
                        is_punctuation = 1;
                        break;
                    }
                }
                
                if (is_punctuation) {
                    if (res_index > 0 && strcmp(res[res_index - 1], "") == 0) {
                        res_index--; // Remove the last empty string
                    }
                    res[res_index++] = strdup((char[]){s[i], '\0'}); // Add punctuation
                    res[res_index++] = strdup(""); // Add empty string
                } else {
                    res[res_index++] = strdup((char[]){s[i], '\0'}); // Add character
                }
            }
        } else {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == '?') {
                continue;
            } else {
                res[res_index++] = strdup((char[]){s[i], '\0'}); // Add character
            }
        }
    }

    // Print the result
    for (int k = 0; k < res_index; k++) {
        printf("%s", res[k]);
        free(res[k]); // Free allocated memory
    }
    
    return 0;
}

// <END-OF-CODE>
