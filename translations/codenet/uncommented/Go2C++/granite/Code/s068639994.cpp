
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ls(n);
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }
    vector<int> lsRev = ls;
    sort(ls.begin(), ls.end());
    sort(lsRev.rbegin(), lsRev.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = min(ls[i], ls[j]), q = max(ls[i], ls[j]);
            int x = q - p, y = q + p;

            int l = lower_bound(ls.begin(), ls.end(), x) - ls.begin();
            int r = n - (upper_bound(lsRev.begin(), lsRev.end(), y) - lsRev.begin());

            int sum = r - l;
            if ((i >= l) && (i <= r)) {
                sum--;
            }
            if ((j >= l) && (j <= r)) {
                sum--;
            }
            sum = max(0, sum);
            ans += sum;
        }
    }

    ans /= 3;
    cout << ans << endl;

    return 0;
}

