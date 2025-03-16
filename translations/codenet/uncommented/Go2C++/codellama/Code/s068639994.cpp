
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> ls(n);
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }
    vector<int> lsRev(n);
    copy(ls.begin(), ls.end(), lsRev.begin());
    sort(ls.begin(), ls.end());
    sort(lsRev.begin(), lsRev.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            int x = q - p;
            int y = q + p;

            int l = lower_bound(ls.begin(), ls.end(), x) - ls.begin();
            int r = n - lower_bound(lsRev.begin(), lsRev.end(), y) - 1;

            int sum = r - l;
            if (i >= l && i <= r) {
                sum--;
            }
            if (j >= l && j <= r) {
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

