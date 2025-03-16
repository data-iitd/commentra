#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mainFn() {
    int n;
    cin >> n;
    vector<int> ls(n);
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }

    vector<int> lsRev = ls;
    sort(ls.begin(), ls.end());
    sort(lsRev.rbegin(), lsRev.rend());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            int x = q - p;
            int y = q + p;

            int l = upper_bound(ls.begin(), ls.end(), x) - ls.begin();
            int r = n - (lower_bound(lsRev.begin(), lsRev.end(), y) - lsRev.begin());

            long long sum = r - l;
            if (i >= l && i < r) {
                sum--;
            }
            if (j >= l && j < r) {
                sum--;
            }
            sum = max(0LL, sum);
            ans += sum;
        }
    }

    ans /= 3;
    cout << ans << endl;
    return 0;
}

int main() {
    mainFn();
    return 0;
}

// <END-OF-CODE>
