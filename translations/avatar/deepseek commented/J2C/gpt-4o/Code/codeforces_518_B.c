#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to reverse the case of a character
char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

int main() {
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];
    
    // Step 1: Read the input string `s` and the target string `t`.
    scanf("%s %s", s, t);
    
    // Initialize counters for the number of replacements
    int ura = 0; // Counter for replacements in step 3
    int opa = 0; // Counter for replacements in step 4
    
    // Step 2: Create a frequency map `tmap` for characters in `t`.
    int tmap[256] = {0}; // Assuming ASCII characters
    for (int i = 0; t[i] != '\0'; i++) {
        tmap[(unsigned char)t[i]]++;
    }
    
    // Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        if (tmap[(unsigned char)ch] > 0) {
            tmap[(unsigned char)ch]--;
            s[i] = 'Я';
            ura++;
        }
    }
    
    // Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = reverse(ch);
        if (tmap[(unsigned char)rch] > 0) {
            tmap[(unsigned char)rch]--;
            opa++;
        }
    }
    
    // Step 5: Print the results `ura` and `opa`.
    printf("%d %d\n", ura, opa);
    
    return 0;
}

// <END-OF-CODE>
