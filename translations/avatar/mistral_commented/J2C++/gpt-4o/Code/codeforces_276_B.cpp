#include <iostream>     // For input and output
#include <unordered_map> // For unordered_map to store character counts
#include <string>      // For string manipulation
using namespace std;

int main() {
    // Initialize input and output streams
    string str;                // String to read from input
    unordered_map<char, int> map; // Map to store character counts
    int oddCount = 0;         // Count of odd-valued character counts

    // Read the first line of input
    getline(cin, str);

    // Iterate through each character in the input string
    for (char ch : str) {
        // Increment the count of the character in the map
        map[ch]++;
    }

    // Iterate through each entry in the map and count odd-valued entries
    for (const auto& entry : map) {
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

    return 0; // End of the program
}

// <END-OF-CODE>
