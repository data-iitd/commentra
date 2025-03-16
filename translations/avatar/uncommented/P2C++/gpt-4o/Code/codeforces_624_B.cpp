#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double pre = numeric_limits<double>::infinity();
    long long ans = 0;
    sort(a.rbegin(), a.rend());

    for (int j = 0; j < n; ++j) {
        ans += max(0LL, min(pre - 1, static_cast<double>(a[j])));
        pre = max(0.0, min(pre - 1, static_cast<double>(a[j])));
    }

    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
