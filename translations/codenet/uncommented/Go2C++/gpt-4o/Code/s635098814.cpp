#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ALPHABET_NUM = 26;

int main() {
    vector<int> memo(ALPHABET_NUM, 0);
    string str;

    while (getline(cin, str)) {
        if (str.empty()) {
            break;
        }
        for (char c : str) {
            if ('a' <= c && c <= 'z') {
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                memo[c - 'A']++;
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << static_cast<char>(i + 'a') << " : " << memo[i] << endl;
    }

    return 0;
}

// <END-OF-CODE>
