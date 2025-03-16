#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'A']++;
    }

    sort(count.begin(), count.end(), greater<int>());

    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] >= k) {
            res += k * k;
            cout << res << endl;
            return 0;
        }
        k -= count[i];
        res += count[i] * count[i];
    }

    cout << res << endl;

    return 0;
}

