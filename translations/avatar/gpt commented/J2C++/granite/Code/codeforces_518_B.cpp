
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    string s, t;
    cin >> s >> t;

    // Initialize counters for unique characters replaced (ura) and reversed characters (opa)
    int ura = 0, opa = 0;

    // Create a map to count occurrences of each character in string t
    map<char, int> tmap;

    // Populate the character frequency map for string t
    for (int i = 0; i < t.length(); i++) {
        char ch = t[i];
        // If the character is not already in the map, add it with a count of 1
        if (tmap.find(ch) == tmap.end()) {
            tmap[ch] = 1;
        } else {
            // If it exists, increment its count
            tmap[ch]++;
        }
    }

    // Get the length of the string for iteration
    int length = s.length();

    // First pass: Replace characters in s with 'Я' and update the frequency map
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        int num = tmap[ch];
        // If the character is not in the map, skip it
        if (num == 0) continue;
        int inum = num;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (inum == 1) {
            tmap.erase(ch);
        } else {
            tmap[ch] = inum - 1;
        }
        // Replace the character in the string with 'Я'
        s[i] = 'Я';
        // Increment the unique character replacement counter
        ura++;
    }

    // Second pass: Check for reversed characters and update the frequency map
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        // Get the reversed character (lowercase to uppercase or vice versa)
        char rch = islower(ch)? toupper(ch) : tolower(ch);
        int num = tmap[rch];
        // If the reversed character is not in the map, skip it
        if (num == 0) continue;
        int inum = num;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (inum == 1) {
            tmap.erase(rch);
        } else {
            tmap[rch] = inum - 1;
        }
        // Increment the reversed character counter
        opa++;
    }

    // Output the counts of unique character replacements and reversed characters
    cout << ura << " " << opa << endl;

    return 0;
}

// Method to reverse the case of a character
char reverse(char ch) {
    // If the character is lowercase, convert it to uppercase
    if (islower(ch)) {
        return toupper(ch);
    } else {
        // If it's uppercase, convert it to lowercase
        return tolower(ch);
    }
}

