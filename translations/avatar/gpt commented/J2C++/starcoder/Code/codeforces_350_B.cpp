#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initialize a scanner for input
    int n;
    cin >> n;
    int a[n + 1];
    int b[n + 1];
    int num[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }
    int ans = 0;
    string ss = "";
    bool st[n + 1];
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            string sss = "";
            sss += to_string(i);
            string sb = sss;
            int x = b[i];
            int s = 1;
            while (!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1) {
                sss = "";
                sss += to_string(x);
                sb += " " + sss;
                st[x] = true;
                x = b[x];
                s++;
            }
            if (s > ans) {
                ans = s;
                ss = sb;
            }
        }
    }
    cout << ans << endl;
    cout << ss << endl;
    return 0;
}

