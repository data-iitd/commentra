
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Create a string variable to store the input string
    string s;
    
    // Read the input string from the user
    cin >> s;
    
    // Convert the input string to a character array
    char targ[s.length()];
    for (int i = 0; i < s.length(); i++) {
        targ[i] = s[i];
    }
    
    // Initialize a map to store the frequency of each character
    map<char, int> map;
    
    // Loop through each character in the array
    for (int i = 0; i < s.length(); i++) {
        // If the character is not already in the map, add it with a count of 1
        if (map.find(targ[i]) == map.end()) {
            map[targ[i]] = 1;
        } else {
            // If the character is already in the map, increment its count
            map[targ[i]]++;
        }
    }
    
    // Initialize a boolean variable to check if the conditions are met
    bool ok = true;
    
    // Check if each character appears exactly twice
    for (auto c : map) {
        if (c.second!= 2) {
            ok = false; // Set ok to false if any character does not appear twice
            break;
        }
    }
    
    // Check if there are exactly two unique characters that appear twice
    if (ok && map.size() == 2) {
        cout << "Yes" << endl; // Output "Yes" if conditions are satisfied
    } else {
        cout << "No" << endl; // Output "No" if conditions are not satisfied
    }
    
    // Return 0 to indicate successful execution
    return 0;
}
