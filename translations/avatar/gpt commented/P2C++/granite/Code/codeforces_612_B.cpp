
#include <iostream>
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

    vector<int> b(n + 1, 0);
    for (int i = 0; i < n; i++) {
        b[a[i]] = i + 1;
    }

    int res = 0;
    for (int i = 2; i <= n; i++) {
        res += abs(b[i] - b[i - 1]);
    }

    cout << res << endl;

    return 0;
}
