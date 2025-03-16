#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

const int ALPHABET_NUM = 26;

int main() {
    // Declare a frequency array for letters.
    vector<int> memo(ALPHABET_NUM, 0);
    string str;

    // Read input until EOF.
    while (getline(cin, str)) {
        for (char c : str) {
            if (islower(c)) {
                // Increment count for lowercase letters.
                memo[c - 'a']++;
            } else if (isupper(c)) {
                // Increment count for uppercase letters.
                memo[c - 'A']++;
            } else {
                // Ignore non-alphabet characters.
                continue;
            }
        }
    }

    // Print the count of each letter.
    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << static_cast<char>(i + 'a') << " : " << memo[i] << endl;
    }

    return 0;
}

// <END-OF-CODE>
