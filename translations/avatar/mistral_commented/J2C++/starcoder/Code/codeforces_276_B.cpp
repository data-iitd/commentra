
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Read the first line of input
    string str;
    getline(cin, str);

    // Initialize the map to store character counts
    map<char, int> map;

    // Iterate through each character in the input string
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i]; // Get the current character

        // If the character is already in the map, increment its count
        if (map.find(ch)!= map.end()) {
            map[ch]++;
        } else {
            // Otherwise, add the character to the map with a count of 1
            map[ch] = 1;
        }
    }

    // Iterate through each entry in the map and count odd-valued entries
    int oddCount = 0;
    for (map<char, int>::iterator it = map.begin(); it!= map.end(); it++) {
        if (it->second % 2!= 0) {
            oddCount++; // Increment the odd count
        }
    }

    // Determine the output based on the odd count
    if (oddCount <= 1 || oddCount % 2!= 0) {
        cout << "First" << endl; // Output "First" if the odd count is 1 or odd
    } else {
        cout << "Second" << endl; // Output "Second" if the odd count is even
    }

    return 0;
}

