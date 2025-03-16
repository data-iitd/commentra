

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> aa(n);
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }

    vector<int> cumsum(n);
    cumsum[0] = aa[0];
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i-1] + aa[i];
    }

    int ans = 2020202020;
    for (int i = 1; i < n-1; i++) {
        int diff1 = abs(cumsum[n-1] - cumsum[i]);
        int diff2 = cumsum[i] - cumsum[0];
        ans = min(ans, diff1, diff2);
    }

    cout << ans << endl;

    return 0;
}

