#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<char, int> map;
    string str;
    int oddCount = 0;

    // Read the first line of input
    getline(cin, str);

    // Iterate through each character in the input string
    for (char ch : str) {
        // If the character is already in the map, increment its count
        if (map.find(ch) != map.end()) {
            map[ch]++;
        } else {
            // Otherwise, add the character to the map with a count of 1
            map[ch] = 1;
        }
    }

    // Iterate through each entry in the map and count odd-valued entries
    for (auto& entry : map) {
        if (entry.second % 2 != 0) {
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
