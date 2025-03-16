

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, r, o = 0, e = 0;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) o++;
        else e++;
    }
    StringBuffer res;
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        if ((r - l + 1) % 2 == 1) {
            res.append("0\n");
        } else {
            if ((r - l + 1) / 2 <= o) {
                res.append("1\n");
            } else {
                res.append("0\n");
            }
        }
    }
    cout << res;
    return 0;
}

