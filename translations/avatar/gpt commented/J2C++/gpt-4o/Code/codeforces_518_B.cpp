#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to reverse the case of a character
char reverse(char ch) {
    // If the character is lowercase, convert it to uppercase
    if (islower(ch)) {
        return toupper(ch);
    } else {
        // If it's uppercase, convert it to lowercase
        return tolower(ch);
    }
}

int main() {
    // Create a string to read the first input
    string s;
    cin >> s;

    // Create a string to read the second input
    string t;
    cin >> t;

    // Initialize counters for unique characters replaced (ura) and reversed characters (opa)
    int ura = 0;
    int opa = 0;

    // Create a map to count occurrences of each character in string t
    unordered_map<char, int> tmap;

    // Populate the character frequency map for string t
    for (char ch : t) {
        tmap[ch]++;
    }

    // Get the length of the string s for iteration
    int length = s.length();

    // First pass: Replace characters in s with 'Я' and update the frequency map
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        auto it = tmap.find(ch);
        // If the character is not in the map, skip it
        if (it == tmap.end()) continue;
        int num = it->second;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (num == 1) {
            tmap.erase(it);
        } else {
            tmap[ch]--;
        }
        // Replace the character in the string with 'Я'
        s[i] = 'Я';
        // Increment the unique character replacement counter
        ura++;
    }

    // Second pass: Check for reversed characters and update the frequency map
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        // Get the reversed character
        char rch = reverse(ch);
        auto it = tmap.find(rch);
        // If the reversed character is not in the map, skip it
        if (it == tmap.end()) continue;
        int num = it->second;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (num == 1) {
            tmap.erase(it);
        } else {
            tmap[rch]--;
        }
        // Increment the reversed character counter
        opa++;
    }

    // Output the counts of unique character replacements and reversed characters
    cout << ura << " " << opa << endl;

    return 0;
}

// <END-OF-CODE>
