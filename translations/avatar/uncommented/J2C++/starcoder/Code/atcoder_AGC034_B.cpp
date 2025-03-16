#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        long long int cnt = 0, tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                tmp++;
            } else if (s[i] == 'D') {
                cnt += tmp;
            } else {
                tmp = 0;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
