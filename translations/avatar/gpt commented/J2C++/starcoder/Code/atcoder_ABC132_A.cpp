#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    char targ[s.length()];
    for (int i = 0; i < s.length(); i++) {
        targ[i] = s[i];
    }
    map<char, int> map;
    for (int i = 0; i < s.length(); i++) {
        if (map.find(targ[i]) == map.end()) {
            map[targ[i]] = 1;
        } else {
            map[targ[i]]++;
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

