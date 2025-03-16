#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string s;
    // Read the input string
    cin >> s;

    unordered_map<char, int> map;
    // Initialize an unordered_map to store character counts

    for (char c : s) {
        // Loop through each character in the string
        map[c]++;
        // Increment the count of the character
    }

    bool ok = true;
    // Initialize a boolean flag to check the conditions

    for (const auto& entry : map) {
        // Loop through each entry in the unordered_map
        if (entry.second != 2) {
            // If any character count is not 2, set ok to false and break the loop
            ok = false;
            break;
        }
    }

    if (ok && map.size() == 2) {
        // Check if all characters appear exactly twice and there are exactly 2 unique characters
        cout << "Yes" << endl;
        // Print "Yes" if the conditions are met
    } else {
        cout << "No" << endl;
        // Print "No" otherwise
    }

    return 0;
}
// <END-OF-CODE>
