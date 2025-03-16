#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Main method declaration
int main() {
    // Create a new string to store the first input string
    string s;
    cin >> s; // Read the first input string from the console
    string t; 
    cin >> t; // Read the second input string from the console

    // Initialize counters for unique characters in the first string and opposite characters in the second string
    int ura = 0;
    int opa = 0;

    // Create an unordered_map to store the frequency of each character in the second string
    unordered_map<char, int> tmap;

    // Read the characters of the second string and store their frequencies in the unordered_map
    for (char ch : t) {
        tmap[ch]++; // Increment the frequency of the character
    }

    // Process the first string
    int length = s.length();
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        auto it = tmap.find(ch);
        if (it == tmap.end()) // If the character is not in the second string
            continue;
        int num = it->second;
        if (num == 1) // If the character appears only once in the second string
            tmap.erase(it); // Remove it from the unordered_map
        else
            tmap[ch]--; // If the character appears more than once in the second string, decrement its frequency
        s[i] = 'Я'; // Replace the character in the string with 'Я'
        ura++; // Increment the counter for unique characters
    }

    // Process the reversed version of the first string
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = reverse(ch); // Get the reverse character of the current character
        auto it = tmap.find(rch);
        if (it == tmap.end()) // If the reverse character is not in the second string
            continue;
        int num = it->second;
        if (num == 1) // If the reverse character appears only once in the second string
            tmap.erase(it); // Remove it from the unordered_map
        else
            tmap[rch]--; // If the reverse character appears more than once in the second string, decrement its frequency
        opa++; // Increment the counter for opposite characters
    }

    // Print the results
    cout << ura << " " << opa << endl;

    return 0;
}

// Reverse the given character
char reverse(char ch) {
    if (islower(ch)) { // If the character is lowercase
        return toupper(ch); // Return its uppercase version
    } else {
        return tolower(ch); // If the character is uppercase, return its lowercase version
    }
}
