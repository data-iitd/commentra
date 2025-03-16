#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> num(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }

    string ss = "";
    int ans = 0;
    vector<bool> st(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            string sss = to_string(i);
            string sb = " " + sss;
            int s = 1;

            while (!st[b[i]] && num[b[i]] == 1 && b[i] != 0 && a[b[i]] != 1) {
                sss = to_string(b[i]);
                sb = " " + sss + sb;
                st[b[i]] = true;
                b[i] = b[b[i]];
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
