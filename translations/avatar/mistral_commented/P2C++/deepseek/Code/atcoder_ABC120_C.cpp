#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    unordered_map<char, int> a;
    for (char c : s) {
        a[c]++;
    }

    int ans = min(a['a'], min(a['b'], a['c'])) * 2;
    cout << ans << endl;

    return 0;
}
