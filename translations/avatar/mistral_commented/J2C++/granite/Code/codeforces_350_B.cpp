

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n + 1], b[n + 1], num[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    string ss = "";
    int ans = 0;
    bool st[n + 1];
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            stringstream sb;
            int x = b[i];
            stringstream sss;
            sss << i;
            sb << " " << sss.str();
            int s = 1;

            while (st[x] == false && num[x] == 1 && x!= 0 && a[x]!= 1) {
                sss.str("");
                sss << x;
                sb << " " << sss.str();
                st[x] = true;
                x = b[x];
                s++;
            }

            if (s > ans) {
                ans = s;
                ss = sb.str();
            }
        }
    }

    cout << ans << endl;
    cout << ss << endl;

    return 0;
}

