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
    vector<int> num(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    string ss = "";
    int ans = 0;
    vector<bool> st(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            stringstream sb;
            int x = b[i];
            stringstream sss;
            sss << i;
            sb << " " << string(sss.str().rbegin(), sss.str().rend());
            int s = 1;

            while (st[x] == false && num[x] == 1 && x != 0 && a[x] != 1) {
                stringstream sss;
                sss << x;
                sb << " " << string(sss.str().rbegin(), sss.str().rend());
                st[x] = true;
                x = b[x];
                s++;
            }

            if (s > ans) {
                ans = s;
                ss = string(sb.str().rbegin(), sb.str().rend());
            }
        }
    }

    cout << ans << endl;
    cout << ss << endl;

    return 0;
}
