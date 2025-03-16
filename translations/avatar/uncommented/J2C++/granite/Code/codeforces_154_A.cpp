
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    unordered_set<string> st;
    int k;
    cin >> k;
    int ans = 0;
    while(k--) {
        string t;
        cin >> t;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == t[0]) a++;
            else if(s[i] == t[1]) b++;
            else {
                ans += min(a, b);
                a = b = 0;
            }
        }
        ans += min(a, b);
    }
    cout << ans << endl;
    return 0;
}

