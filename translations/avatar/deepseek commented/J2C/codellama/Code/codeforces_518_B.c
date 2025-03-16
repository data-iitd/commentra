
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Step 1: Read the input string `s` and the target string `t`.
    char s[1000000];
    char t[1000000];
    scanf("%s", s);
    scanf("%s", t);
    
    // Initialize counters for the number of replacements
    int ura = 0; // Counter for replacements in step 3
    int opa = 0; // Counter for replacements in step 4
    
    // Step 2: Create a frequency map `tmap` for characters in `t`.
    int tmap[256];
    memset(tmap, 0, sizeof(tmap));
    for (int i = 0; i < strlen(t); i++) {
        tmap[t[i]]++;
    }
    
    // Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (tmap[s[i]] == 1) {
            tmap[s[i]]--;
            s[i] = 'Я';
            ura++;
        } else if (tmap[s[i]] > 1) {
            tmap[s[i]]--;
        }
    }
    
    // Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
    for (int i = 0; i < length; i++) {
        if (tmap[reverse(s[i])] == 1) {
            tmap[reverse(s[i])]--;
            opa++;
        } else if (tmap[reverse(s[i])] > 1) {
            tmap[reverse(s[i])]--;
        }
    }
    
    // Step 5: Print the results `ura` and `opa`.
    printf("%d %d\n", ura, opa);
    
    return 0;
}

// Helper method to reverse the case of a character
char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

