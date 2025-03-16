
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    char targ[s.length()];
    strcpy(targ, s.c_str());
    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); i++) {
        if (map.find(targ[i]) == map.end()) {
            map[targ[i]] = 1;
        } else {
            map[targ[i]] += 1;
        }
    }
    bool ok = true;
    for (auto c : map) {
        if (c.second!= 2) {
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
//END-OF-CODE