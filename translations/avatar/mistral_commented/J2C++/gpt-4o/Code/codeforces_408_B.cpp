#include <iostream> // For handling input/output
#include <unordered_map> // For using unordered_map
#include <unordered_set> // For using unordered_set
#include <string> // For using string
using namespace std;

bool isValid(const string& s1, const string& s2) { // Check if the given strings are valid
    unordered_map<char, bool> map; // Create an unordered_map to store the presence of characters in the first string

    for (char c : s1) { // Iterate through each character in the first string
        map[c] = true; // Mark the character as present in the unordered_map
    }

    for (char c : s2) { // Iterate through each character in the second string
        if (map.find(c) == map.end()) { // If the character is not present in the first string, return false
            return false;
        }
    }

    return true; // If all characters in the second string are present in the first string, return true
}

int main() {
    string s1, s2; // Declare strings to hold input
    cin >> s1 >> s2; // Read the first and second strings from the input

    if (!isValid(s1, s2)) { // Check if the given strings are valid
        cout << -1 << endl; // If not valid, print -1 and exit
    } else { // If the strings are valid, proceed with the computation
        unordered_map<char, int> m1; // Create an unordered_map to store the frequency of characters in the first string
        unordered_map<char, int> m2; // Create an unordered_map to store the frequency of characters in the second string

        for (char c : s1) { // Iterate through each character in the first string
            m1[c]++; // Increment the count of the character
        }

        for (char c : s2) { // Iterate through each character in the second string
            m2[c]++; // Increment the count of the character
        }

        int ans = 0; // Initialize the answer variable to 0
        unordered_set<char> hs; // Create an unordered_set to store unique characters in the second string

        for (char c : s2) { // Iterate through each character in the second string
            if (hs.find(c) == hs.end()) { // If the character is not already in the unordered_set, add it and compute the answer
                hs.insert(c); // Add the character to the unordered_set
                int x1 = m1[c]; // Get the count of the character in the first string
                int x2 = m2[c]; // Get the count of the character in the second string
                x1 = min(x1, x2); // Take the minimum count
                ans += x1; // Add the minimum count to the answer
            }
        }

        cout << ans << endl; // Print the answer
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
