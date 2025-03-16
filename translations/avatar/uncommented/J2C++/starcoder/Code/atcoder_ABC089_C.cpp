#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long cnt[5] = {0};
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (s[0] == 'M') {
                cnt[0]++;
            } else if (s[0] == 'A') {
                cnt[1]++;
            } else if (s[0] == 'R') {
                cnt[2]++;
            } else if (s[0] == 'C') {
                cnt[3]++;
            } else if (s[0] == 'H') {
                cnt[4]++;
            }
        }
        long long res = cnt[0] * cnt[1] * cnt[2] + cnt[0] * cnt[1] * cnt[3] + cnt[0] * cnt[1] * cnt[4] + cnt[0] * cnt[2] * cnt[3] + cnt[0] * cnt[2] * cnt[4] + cnt[0] * cnt[3] * cnt[4] + cnt[1] * cnt[2] * cnt[3] + cnt[1] * cnt[2] * cnt[4] + cnt[1] * cnt[3] * cnt[4] + cnt[2] * cnt[3] * cnt[4];
        cout << res << "\n";
    }
    return 0;
}

