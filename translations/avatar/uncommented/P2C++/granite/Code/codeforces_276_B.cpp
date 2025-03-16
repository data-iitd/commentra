
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> dt;
    for (char i : s) {
        if (dt.find(i)!= dt.end()) {
            dt[i]++;
        } else {
            dt[i] = 1;
        }
    }
    int cnt = 0;
    bool x = true;
    for (auto [key, value] : dt) {
        if (value % 2!= 0 && cnt < 1) {
            cnt++;
        } else if (value % 2!= 0 && cnt >= 1) {
            x = false;
            break;
        }
    }
    if (x) {
        cout << "First" << endl;
    } else if (!x && s.length() % 2 == 0) {
        cout << "Second" << endl;
    } else if (!x && s.length() % 2!= 0) {
        cout << "First" << endl;
    }
    return 0;
}
