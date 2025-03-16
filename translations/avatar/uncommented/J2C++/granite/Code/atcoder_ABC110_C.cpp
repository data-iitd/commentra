
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S, T;
    getline(cin, S);
    getline(cin, T);
    vector<string> A = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    bool res = true;
    for (string s : A) {
        int sIdx = S.find(s);
        if (sIdx == string::npos) continue;
        string t = string(1, T[sIdx]);
        int idx = 0;
        while (idx < S.length()) {
            if (S.find(s, idx)!= string::npos) {
                if (S.find(s, idx)!= T.find(t, idx)) {
                    res = false;
                    break;
                } else {
                    idx = S.find(s, idx) + 1;
                }
            } else if (T.find(t, idx)!= string::npos) {
                res = false;
                break;
            } else break;
        }
        if (!res) break;
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
// END-OF-CODE