#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<int, string> map;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map[i] = s;
    }
    bool ans = true;
    map<int, string> past;
    string next = "";
    for (int i = 0; i < N; i++) {
        if (past.count(map[i]) > 0) {
            ans = false;
            break;
        }
        past[i] = map[i];
        if (i!= 0) {
            if (next!= map[i][0]) {
                ans = false;
                break;
            }
        }
        next = map[i][map[i].length() - 1];
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
