#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    int ans = 1, sumL = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!') {
            string t = s.substr(0, i + 1);
            t.erase(remove(t.begin(), t.end(),''), t.end());
            int L = t.size();
            if (L > n) {
                cout << "Impossible" << endl;
                return 0;
            }
            if (sumL + L + (sumL > 0)) {
                ans++;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
            s.erase(0, i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}

