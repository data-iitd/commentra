
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m.push_back(s);
    }
    bool possible = true;
    for (auto i : m) {
        if (count(m.begin(), m.end(), i) >= n / 2 + 1) {
            possible = false;
            break;
        }
    }
    cout << (possible? "YES" : "NO") << endl;
    return 0;
}

