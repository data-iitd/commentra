
#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main() {
    // Initialize input and output streams
    string str;                 // String to read from input
    map<char, int> map;         // Map to store character counts
    int oddCount;               // Count of odd-valued character counts

    // Read the first line of input
    getline(cin, str);

    // Initialize the map to store character counts
    map = map<char, int>();

    // Iterate through each character in the input string
    for (int i = 0; i < str.length(); i++) {
        char ch = str.at(i); // Get the current character

        // If the character is already in the map, increment its count
        if (map.find(ch) != map.end()) {
            map[ch] = map[ch] + 1;
        } else {
            // Otherwise, add the character to the map with a count of 1
            map[ch] = 1;
        }
    }

    // Iterate through each entry in the map and count odd-valued entries
    for (map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
        if (it->second % 2 != 0) {
            oddCount++; // Increment the odd count
        }
    }

    // Determine the output based on the odd count
    if (oddCount <= 1 || oddCount % 2 != 0) {
        cout << "First" << endl; // Output "First" if the odd count is 1 or odd
    } else {
        cout << "Second" << endl; // Output "Second" if the odd count is even
    }

    return 0;
}

