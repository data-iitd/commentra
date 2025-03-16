#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    auto na = []() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        return a;
    };

    int n, x;
    cin >> n >> x;
    vector<int> a = na();
    sort(a.begin(), a.end());
    int ans = 0;
    if (a[0] > x) {
        cout << 0 << endl;
        return 0;
    }
    for (int i : a) {
        if (i > x) {
            x = 0;
            break;
        }
        x -= i;
        ans += 1;
    }
    if (x != 0) {
        ans -= 1;
    }
    cout << ans << endl;
    return 0;
}
