
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Set up input and output streams
    string str;
    cin >> str;

    // Create a HashMap to count the frequency of each character in the input string
    map<char, int> map;

    // Initialize a counter for characters with odd frequencies
    int oddCount = 0;

    // Iterate through the input string to populate the frequency map
    for (int i = 0; i < str.length(); i++) {
        char ch = str.at(i);
        if (map.find(ch) != map.end()) {
            map[ch]++;
        } else {
            map[ch] = 1;
        }
    }

    // Iterate through the map to count characters with odd frequencies
    for (map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
        if (it->second % 2 != 0) {
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

