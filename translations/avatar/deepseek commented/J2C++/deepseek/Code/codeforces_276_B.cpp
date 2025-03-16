#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Set up input and output streams
    string str;
    getline(cin, str);

    // Create an unordered_map to count the frequency of each character in the input string
    unordered_map<char, int> map;

    // Initialize a counter for characters with odd frequencies
    int oddCount = 0;

    // Iterate through the input string to populate the frequency map
    for (char ch : str) {
        map[ch]++;
    }

    // Iterate through the map to count characters with odd frequencies
    for (auto& entry : map) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }

    // Determine the winner based on the count of characters with odd frequencies
    if (oddCount <= 1 || oddCount % 2 != 0) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
