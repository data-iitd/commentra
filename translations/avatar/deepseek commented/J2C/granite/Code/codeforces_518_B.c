

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Step 1: Read the input string `s` and the target string `t`.
    char s[100001];
    char t[100001];
    fgets(s, 100001, stdin);
    fgets(t, 100001, stdin);
    
    // Initialize counters for the number of replacements
    int ura = 0; // Counter for replacements in step 3
    int opa = 0; // Counter for replacements in step 4
    
    // Step 2: Create a frequency map `tmap` for characters in `t`.
    int tmap[256] = {0};
    for (int i = 0; i < strlen(t); i++) {
        tmap[t[i]]++;
    }
    
    // Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        if (tmap[ch] > 0) {
            tmap[ch]--;
            s[i] = 'Я';
            ura++;
        }
    }
    
    // Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = (ch >= 'a' && ch <= 'z')? ch - 32 : ch + 32;
        if (tmap[rch] > 0) {
            tmap[rch]--;
            opa++;
        }
    }
    
    // Step 5: Print the results `ura` and `opa`.
    printf("%d %d\n", ura, opa);
    
    return 0;
}
