#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    int ans = n - 1;
    int last = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(last - l[i]) + 1;
        last = l[i];
    }
    cout << ans << endl;
    return 0;
}

