
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    struct arm {
        int l, r;
    };

    vector<arm> as(n);
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        as[i].l = x - l;
        as[i].r = x + l;
    }

    sort(as.begin(), as.end(), [](const arm &a, const arm &b) { return a.r < b.r; });

    int ans = 1, r = as[0].r;
    for (int i = 1; i < n; i++) {
        if (as[i].l >= r) {
            ans++;
            r = as[i].r;
        }
    }

    cout << ans << endl;

    return 0;
}

