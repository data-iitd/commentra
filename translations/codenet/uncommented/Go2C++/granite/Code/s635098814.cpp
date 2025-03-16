

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const int INF_INT64 = numeric_limits<int64_t>::max();
const int64_t INF_BIT60 = 1LL << 60;

int memo[ALPHABET_NUM];
string str;

int main() {
    while (getline(cin, str)) {
        if (str.empty()) {
            break;
        }
        for (char c : str) {
            if ('a' <= c && c <= 'z') {
                // toUpper
                // c-('a'-'A')
                memo[c-'a']++;
            } else if ('A' <= c && c <= 'Z') {
                // toLower
                // c+('a'-'A')
                memo[c-'A']++;
            } else {
                // stay
                // c
                continue;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << char(i+'a') << " : " << memo[i] << endl;
    }

    return 0;
}

