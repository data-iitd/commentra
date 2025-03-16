
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    char s[1000];
    char t[1000];
    scanf("%s", s);
    scanf("%s", t);

    // Initialize counters for unique characters replaced (ura) and reversed characters (opa)
    int ura = 0;
    int opa = 0;

    // Create a map to count occurrences of each character in string t
    int tmap[256] = {0};
    int i;
    for (i = 0; t[i]!= '\0'; i++) {
        tmap[t[i]]++;
    }

    // Get the length of the StringBuilder for iteration
    int length = strlen(s);

    // First pass: Replace characters in s with 'Я' and update the frequency map
    for (i = 0; i < length; i++) {
        char ch = s[i];
        int num = tmap[ch];
        // If the character is not in the map, skip it
        if (num == 0) continue;
        int inum = num;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (inum == 1) {
            tmap[ch] = 0;
        } else {
            tmap[ch] = inum - 1;
        }
        // Replace the character in the StringBuilder with 'Я'
        s[i] = 'Я';
        // Increment the unique character replacement counter
        ura++;
    }

    // Second pass: Check for reversed characters and update the frequency map
    for (i = 0; i < length; i++) {
        char ch = s[i];
        // Get the reversed character (lowercase to uppercase or vice versa)
        char rch = (ch >= 'a' && ch <= 'z')? toupper(ch) : tolower(ch);
        int num = tmap[rch];
        // If the reversed character is not in the map, skip it
        if (num == 0) continue;
        int inum = num;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (inum == 1) {
            tmap[rch] = 0;
        } else {
            tmap[rch] = inum - 1;
        }
        // Increment the reversed character counter
        opa++;
    }

    // Output the counts of unique character replacements and reversed characters
    printf("%d %d\n", ura, opa);

    return 0;
}
