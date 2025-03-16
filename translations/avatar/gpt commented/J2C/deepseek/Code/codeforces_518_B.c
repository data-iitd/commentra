#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <map>

int main() {
    // Create a map to count occurrences of each character in string t
    std::map<char, int> tmap;

    // Read the first string and initialize a StringBuilder with it
    char s[100];
    scanf("%s", s);

    // Read the second string
    char t[100];
    scanf("%s", t);

    // Initialize counters for unique characters replaced (ura) and reversed characters (opa)
    int ura = 0;
    int opa = 0;

    // Populate the character frequency map for string t
    for (int i = 0; i < strlen(t); i++) {
        char ch = t[i];
        // If the character is not already in the map, add it with a count of 1
        if (tmap.find(ch) == tmap.end())
            tmap[ch] = 1;
        else
            // If it exists, increment its count
            tmap[ch]++;
    }

    // Get the length of the string s for iteration
    int length = strlen(s);

    // First pass: Replace characters in s with 'Я' and update the frequency map
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        auto it = tmap.find(ch);
        // If the character is not in the map, skip it
        if (it == tmap.end()) continue;
        int num = it->second;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (num == 1)
            tmap.erase(it);
        else
            tmap[ch] = num - 1;
        // Replace the character in the string with 'Я'
        s[i] = 'Я';
        // Increment the unique character replacement counter
        ura++;
    }

    // Second pass: Check for reversed characters and update the frequency map
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        // Get the reversed character (lowercase to uppercase or vice versa)
        char rch = tolower(ch) == ch ? toupper(ch) : tolower(ch);
        auto it = tmap.find(rch);
        // If the reversed character is not in the map, skip it
        if (it == tmap.end()) continue;
        int num = it->second;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (num == 1)
            tmap.erase(it);
        else
            tmap[rch] = num - 1;
        // Increment the reversed character counter
        opa++;
    }

    // Output the counts of unique character replacements and reversed characters
    printf("%d %d\n", ura, opa);

    return 0;
}
