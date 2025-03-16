

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> map;
    for (char c : s) {
        map[c]++;
    }
    bool ok = true;
    for (auto it : map) {
        if (it.second!= 2) {
            ok = false;
            break;
        }
    }
    if (ok && map.size() == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

