#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

void solution() {
    string line;
    getline(cin, line);
    unordered_map<char, int> bought_count;
    for (char c : line) {
        bought_count[c]++;
    }

    getline(cin, line);
    unordered_map<char, int> made_count;
    for (char c : line) {
        made_count[c]++;
    }

    int res = 0;
    for (const auto& pair : made_count) {
        char color = pair.first;
        if (bought_count.find(color) == bought_count.end()) {
            cout << -1 << endl;
            return;
        }
        res += min(bought_count[color], made_count[color]);
    }
    cout << res << endl;
}

int main() {
    int t = 1;
    for (int i = 0; i < t; i++) {
        solution();
    }
    return 0;
}

// <END-OF-CODE>
