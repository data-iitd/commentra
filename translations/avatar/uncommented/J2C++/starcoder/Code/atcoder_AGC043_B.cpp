#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    for (int i = 1; i < n; i++) {
        ans += to_string(abs(s[i] - s[i - 1]));
    }
    if (n == 2) {
        cout << ans[0];
        return 0;
    }
    if (ans.find("1")!= string::npos) {
        cout << cal(ans, '1');
    } else {
        cout << cal(ans, '2') * 2;
    }
    return 0;
}

