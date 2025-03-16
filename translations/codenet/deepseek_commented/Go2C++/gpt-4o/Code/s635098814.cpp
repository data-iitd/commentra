#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

// Constants
const int ALPHABET_NUM = 26;

int main() {
    string str;
    vector<int> memo(ALPHABET_NUM, 0);

    // Read input until EOF
    while (getline(cin, str)) {
        for (char c : str) {
            if (islower(c)) {
                memo[c - 'a']++;
            } else if (isupper(c)) {
                memo[c - 'A']++;
            }
        }
    }

    // Print the counts of each letter
    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << static_cast<char>(i + 'a') << " : " << memo[i] << endl;
    }

    return 0;
}

// <END-OF-CODE>
