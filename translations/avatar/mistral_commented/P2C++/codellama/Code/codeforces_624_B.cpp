#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int pre = INT_MAX;
    int ans = 0;
    for (int j = 0; j < n; j++) {
        ans += max(0, min(pre - 1, a[j]));
        pre = min(pre - 1, a[j]);
    }
    cout << ans << endl;
    return 0;
}

