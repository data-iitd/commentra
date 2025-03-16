#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string line;
        cin >> line;
        int bought_count[26] = {0};
        for (char c : line) {
            bought_count[c - 'a']++;
        }
        cin >> line;
        int made_count[26] = {0};
        for (char c : line) {
            made_count[c - 'a']++;
        }
        int res = 0;
        for (int j = 0; j < 26; j++) {
            if (made_count[j] == 0) {
                continue;
            }
            if (bought_count[j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            res += min(bought_count[j], made_count[j]);
        }
        cout << res << endl;
    }
    return 0;
}
