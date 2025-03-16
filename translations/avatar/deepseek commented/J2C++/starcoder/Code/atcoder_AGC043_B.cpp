
#include <bits/stdc++.h>
using namespace std;

int cal(string s, char c) {
    int n = s.length();
    int m = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == c && (m & i) == i) {
            ans ^= 1;
        }
    }
    return ans;
}

void solve() {
    int n = sc.nextInt();
    string s = sc.next();
    string ans = "";
    for (int i = 1; i < n; i++) {
        ans += abs(s[i] - s[i - 1]);
    }
    if (n == 2) {
        out.println(ans[0]);
        return;
    }
    if (ans.find("1")!= string::npos) {
        out.println(cal(ans, '1'));
    } else {
        out.println(cal(ans, '2') * 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

